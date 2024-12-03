#ifndef VIDEO_GAME_RECOMMENDER_GAME_H
#define VIDEO_GAME_RECOMMENDER_GAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
using namespace std;

class Game{
    public:
        string name;
        int metacritic;
        double rating;
        int achievementCount;
        int suggestionsCount;
        unordered_set<string> gameGenres;
        unordered_set<string> gamePlatforms;

    Game(const string& name,double metacritic, double rating, int suggestionsCount, int achievementCount, const unordered_set<string>& gameGenres,
         const unordered_set<string>& gamePlatforms){
            this->name = name;
            this->metacritic = metacritic;
            this->rating = rating;
            this->suggestionsCount = suggestionsCount;
            this->achievementCount = achievementCount;
            this->gameGenres = gameGenres;
            this->gamePlatforms = gamePlatforms;
        }

    void dispalyByMetacritic() const{
        cout << "Name: " << name << " - ";
        cout << "Metacritic Rating: " << metacritic << endl;
    }

    void displayByAchievementCount() const{
        cout << "Name: " << name << " - ";
        cout << "Achievement Count: " << achievementCount << endl;
    }

    void displayBySuggestionCount() const{
        cout << "Name: " << name << " - ";
        cout << "Suggestion Count: " << suggestionsCount << endl;
    }
};

#endif //VIDEO_GAME_RECOMMENDER_GAME_H
