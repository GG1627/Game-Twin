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
//            op.games[i].dispalyByMetacritic();
            gameFound = true;
            break;
        }
    }

    if (!gameFound) {
        cout << "Game not found." << endl;  // if game not found
    }

    Similar sim(op.games);

    vector<Game> similarGames = sim.extractGenre(gameName);  // Call the function to get similar games
    similarGames = sim.extractPlatform(gamePlatform, similarGames);  // Call the function to get similar games

    int selection;
    cout << "Select 1 for a QuickSort, Select 2 for a CocktailSort." << endl;
    cin >> selection;

    int sortBySelection;
    cout << "Select 1 for sort by Metacritic, Select 2 for sort by Achievement Count, Select 3 for sort by Suggestion Count." << endl;
    cin >> sortBySelection;

    auto start = std::chrono::high_resolution_clock::now();
    if(selection == 1) {
        if(sortBySelection == 1){
            algo.quickSortMetacritic(similarGames, 0 ,similarGames.size()-1);
        }
        else if(sortBySelection == 2){
            algo.quickSortAchievmentCount(similarGames, 0 ,similarGames.size()-1);
        }
        else if(sortBySelection == 3){
            algo.quickSortSuggestionsCount(similarGames, 0 ,similarGames.size()-1);
        }
    }
    else if(selection == 2){
        if(sortBySelection == 1) {
            algo.cocktailSortMetacritic(similarGames, similarGames.size());
        }
        else if(sortBySelection == 2){
            algo.cocktailSortAchievementCount(similarGames, similarGames.size());
        }
        else if(sortBySelection == 3){
            algo.cocktailSortSuggestionsCount(similarGames, similarGames.size());
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    // reverse the vector for in order printing
    reverse(similarGames.begin(), similarGames.end());
    for(int p=0; p < 5; p++){
            if(p==0){
                cout << "1. ";
                if(sortBySelection == 1) {
                    similarGames[p].dispalyByMetacritic();
                }
                else if(sortBySelection == 2){
                    similarGames[p].displayByAchievementCount();
                }
                else if(sortBySelection == 3){
                    similarGames[p].displayBySuggestionCount();
                }
                cout << "\n" << endl;
            }
            else if(p==1){
                cout << "2. ";
                if(sortBySelection == 1) {
                    similarGames[p].dispalyByMetacritic();
                }
                else if(sortBySelection == 2){
                    similarGames[p].displayByAchievementCount();
                }
                else if(sortBySelection == 3){
                    similarGames[p].displayBySuggestionCount();
                }
                cout << "\n" << endl;
                
            }
            else if(p==2){
                cout << "3. ";
                if(sortBySelection == 1) {
                    similarGames[p].dispalyByMetacritic();
                }
                else if(sortBySelection == 2){
                    similarGames[p].displayByAchievementCount();
                }
                else if(sortBySelection == 3){
                    similarGames[p].displayBySuggestionCount();
                }
                cout << "\n" << endl;
            }
            else if(p==3){
                cout << "4. ";
                if(sortBySelection == 1) {
                    similarGames[p].dispalyByMetacritic();
                }
                else if(sortBySelection == 2){
                    similarGames[p].displayByAchievementCount();
                }
                else if(sortBySelection == 3){
                    similarGames[p].displayBySuggestionCount();
                }
                cout << "\n" << endl;
            }
            else if(p==4){
                cout << "5. ";
                if(sortBySelection == 1) {
                    similarGames[p].dispalyByMetacritic();
                }
                else if(sortBySelection == 2){
                    similarGames[p].displayByAchievementCount();
                }
                else if(sortBySelection == 3){
                    similarGames[p].displayBySuggestionCount();
                }
                cout << "\n" << endl;
            }
    }

    std::cout << "Time of sorting method: " << elapsed.count() << " ms\n";
}