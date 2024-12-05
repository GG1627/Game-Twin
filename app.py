from flask import Flask, render_template, request
import subprocess

app = Flask(__name__)

# global variables to store user inputs
inputs = {}

# define root route for welcome page
@app.route('/')
def welcome():
    return render_template('index.html')

@app.route('/next', methods=['GET', 'POST'])
def next_page():
    if request.method == 'POST':
        # get game name and console from form
        game_name = request.form['game_name']
        game_console = request.form['game_console']

        # check if either field is empty
        if not game_name or not game_console:
            error_message = "Please fill all fields"
            return render_template('next.html', error_message=error_message)
        
        inputs['game_name'] = game_name
        inputs['game_console'] = game_console
        return render_template('sorting.html')
    # handle GET request to render the form
    return render_template('next.html')
    
# define the route for the sorting page where users select sorting options
@app.route('/sorting', methods=['POST'])
def sorting_page():
    # retrieve game name and console from the global `inputs` dictionary
    game_name = inputs.get('game_name', '').strip()
    game_console = inputs.get('game_console', '').strip()

    # initally validate inputs to ensure no fields are empty
    if not game_name or not game_console:
        error_message = "Game could not be found in dataset"
        return render_template('next.html', error_message=error_message, game_name=game_name, game_console=game_console)

    # initialize time_taken with a default value
    time_taken = "N/A"

    # get sorting algorithm and search criteria from the form
    inputs['sorting_algorithm'] = request.form['algorithm']
    inputs['search_criteria'] = request.form['search-criteria']

    # call the C++ program with these inputs
    cpp_executable = "./main.exe"

    input_data = f"{inputs['game_name']}\n{inputs['game_console']}\n{inputs['sorting_algorithm']}\n{inputs['search_criteria']}\n"

    # Execute the C++ program with the provided inputs
    try:
        process = subprocess.run(
            [cpp_executable],
            input=input_data,
            text=True,
            capture_output=True,
            check=True
        )
        cpp_output = process.stdout
        print(cpp_output)
        # process the output to extract the list of games
        lines = cpp_output.splitlines()  # split output into individual lines

        if any("Game not found." in line for line in lines):
            error_message = "Game was not found, please try another title"
            return render_template('next.html', error_message=error_message)
        
        formatted_output = []  # to store structured output
        game_name = inputs.get('game_name')  
        time_taken = None    
        for i in range(len(lines)):
            if lines[i].strip().startswith(f"{len(formatted_output)+1}."):
                # add the numbered line
                entry = lines[i].strip()
                # check if the next line contains additional game details
                if i + 1 < len(lines):
                    entry += f"\n{lines[i + 1].strip()}"
                formatted_output.append(entry)
         # retrieve the time taken for processing from the last line of the output
        if lines:
            time_taken = lines[-1].strip()
    except subprocess.CalledProcessError as e:
        # checks for non-zero exit status errors
        if "Game not found." in e.stdout:
            error_message = "Game was not found, please try another title"
            return render_template('next.html', error_message=error_message, game_name=game_name, game_console=game_console)
        else:
            error_message = f"Game console does not exist, please try another platform"
            return render_template('next.html', error_message=error_message, game_name=game_name, game_console=game_console)
        
    # render the results page
    return render_template('final.html', games=formatted_output, game=game_name, time_taken=time_taken)

if __name__ == '__main__':
    app.run(debug=True)
