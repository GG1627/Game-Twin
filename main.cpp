#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Game.h"
#include "Similar.h"
#include "ParseData.h"
#include "SortingAlgorithms.h"
#include <chrono>

using namespace std;

int main(){
    // objects created for the operations needed to perform on the game vector
    ParseData op;
    SortingAlgorithms algo;
    op.ParseCSVFile();
    cout << "everything worked" << endl;

    // get user input
    string gameName;
    cout << "What game would you like to find?" << endl;
    getline(cin, gameName);

    string gamePlatform;
    cout << "What platform is the game on?" << endl;
    getline(cin, gamePlatform);

    // find the game
    bool gameFound = false;  // flag to see if game found

    for(size_t i=0; i < op.games.size(); i++){
        if(op.games[i].name == gameName){
            cout << "Game found" << endl;
            gameFound = true;
            break;
        }
    }

    if (!gameFound) {
        cout << "Game not found." << endl;  // if game not found
    }

    // creates a similar object to get the filtered vector and places it in a new vector
    Similar sim(op.games);
    vector<Game> similarGames = sim.extractParameters(gameName, gamePlatform);  // Call the function to get similar games

    // gets user input for what selection and parameter and algorithm they want to sort by
    int selection;
    cout << "Select 1 for a QuickSort, Select 2 for a CocktailSort." << endl;
    cin >> selection;

    int sortBySelection;
    cout << "Select 1 for sort by Metacritic, Select 2 for sort by Achievement Count, Select 3 for sort by Suggestion Count." << endl;
    cin >> sortBySelection;

    // clock to keep track of how long the sort takes
    auto start = std::chrono::high_resolution_clock::now();

    // input handling
    if(selection == 1) {
        if(sortBySelection == 1){
            algo.quickSortMetacritic(similarGames, 0 ,similarGames.size()-1);
            reverse(similarGames.begin(), similarGames.end());
        }
        else if(sortBySelection == 2){
            sim.findDifference(gameName, similarGames);
            algo.quickSortAchievmentCount(similarGames, 0 ,similarGames.size()-1);
        }
        else if(sortBySelection == 3){
            algo.quickSortSuggestionsCount(similarGames, 0 ,similarGames.size()-1);
            reverse(similarGames.begin(), similarGames.end());
        }
    }
    else if(selection == 2){
        if(sortBySelection == 1) {
            algo.cocktailSortMetacritic(similarGames, similarGames.size());
        }
        else if(sortBySelection == 2){
            sim.findDifference(gameName, similarGames);
            algo.cocktailSortAchievementCount(similarGames, similarGames.size());
        }
        else if(sortBySelection == 3){
            algo.cocktailSortSuggestionsCount(similarGames,similarGames.size());
        }
    }

    // stops the clock and stores the result
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    // outputs the most similar games, as well as displays the time the sort took
    for(int p=0; p < 5; p++){
        cout <<  (p+1) << ". ";
        if(sortBySelection == 1) {
            similarGames[p].displayByMetacritic();
            cout << "\n";
        }
        else if(sortBySelection == 2){
            similarGames[p].displayByAchievementCount();
            cout << "\n";
        }
        else if(sortBySelection == 3){
            similarGames[p].displayBySuggestionCount();
            cout << "\n";
        }
    }
    std::cout << "Time of sorting method: " << elapsed.count() << " ms\n";
}
