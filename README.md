<h3 align="center">Game Twin</h3>

![Screenshot 2024-12-04 124835](https://github.com/user-attachments/assets/96f2d60c-43a8-4071-8c2f-26a637bbad60)

# Collaborators:
- Alejandro Gonzalez - https://github.com/alejgonza04
- Gael Garcia - https://github.com/GG1627
- John Lewis - https://github.com/broncosfan915

# Technologies Used
C++, Python, HTML, CSS, Flask, Django

# About 
This was created as a collaborative final project for our Data Structures and Algorithms class. After several conversations between group members, we decided to create a project that focused on the efficiency of certain sorting algorithms. These algorithms were Quick Sort and Cocktail Sort.
# Features
### Overview
Game Twin is a web application designed to help you relive the joy of your favorite video games by finding the perfect match. Leveraging a dataset of over 470,0000 video games, Game Twin analyzes key attributes to recommend the most similar titles, ensuring you can recreate the nostalgia you had when picking the game up for the first time.

### How It Works
- We utilized a Kaggle dataset that had over 470,000 video game entries, as well as their respective genre, metacritic rating, achievement count, suggestion count, etc.
- This dataset was parsed in C++ and sorted using Quick Sort and Cocktail Sort based on what parameters were requested to sort by.
- Python, Django, and Flask were used to connect the C++ code to the HTML and CSS frontend. To do this, the subprocess Python module was employed to parse the output of the C++ code and capture results. These results were then passed to the frontend to be shown.

# Collecting Initial Data
![Screenshot 2024-12-04 124851](https://github.com/user-attachments/assets/2cef139c-e353-411d-9b42-5ff9197b72a8)
- Users are prompted to enter their game's name and what console they want to find similar games on.
# What Sorting Algorithm and Search Criteria To Use
![Screenshot 2024-12-04 124858](https://github.com/user-attachments/assets/5b84454e-2c40-4b5b-9b7b-5d968f7ce8f3)

- Users are prompted to choose a sorting algorithm as well as what search criteria to sort the games by.

# How The Results Are Collected
- The C++ code initially takes in the game's name, finds that game, then filters out all game's in the dataset that don't have that game's same genre.
- Based on the game console, the dataset is then further filters out all game's that aren't on that console.
- Utilizing the sorting method and the search criteria, the dataset is then sorted.

# The Results
![Screenshot 2024-12-04 124910](https://github.com/user-attachments/assets/4b2996b0-bcee-43d5-bf1c-28b87cd4afab)

- Users are shown the time taken by the sorting algorithm and are given a list of games that meet their search criteria and what those values are.
- 
# Resources
https://www.kaggle.com/datasets/jummyegg/rawg-game-dataset

# Author
Alejandro Gonzalez - https://github.com/alejgonza04
