#include "Similar.h"

// searches the game vector to see if the user inputted name is in it, and if true, returns the game object
Game Similar::findGame(string name){
    for(const auto& game : gamesRef) {
        if(game.name == name) {
            return game;
        }
    }
    throw runtime_error("Game not found!");
}

// returns a pair of unordered_sets where the first in the pair is the genres, and the second is the platforms
pair<unordered_set<string>, unordered_set<string>> Similar::getParameters(string gameName) {
    return {findGame(gameName).gameGenres, findGame(gameName).gamePlatforms};
}

// filters down the original vector by first removing games that don't have similar genres, then games that are not on the selected platform
vector<Game> Similar::extractParameters(string gameName, string gamePlatform) {
    vector<Game> filteredGames;
    pair<unordered_set<string>, unordered_set<string>> targetParameters = getParameters(gameName);

    for (int i = 0; i < gamesRef.size(); i++) {
        unordered_set<string> currGenres = getParameters(gamesRef[i].name).first;
        for (auto it = currGenres.begin(); it != currGenres.end(); ++it) {
            if (targetParameters.first.find(*it) != targetParameters.first.end() && gamesRef[i].name != gameName) {
                filteredGames.push_back(gamesRef[i]);
                break;
            }
        }
    }

    // takes the partially extracted vector, and then further filters it, now by platform
    vector<Game> platformFilteredGames;
    for (int i = 0; i < filteredGames.size(); i++) {
        unordered_set<string> currPlatforms = getParameters(filteredGames[i].name).second;
        // Check if the user-provided platform exists in the current game's platforms
        if (currPlatforms.find(gamePlatform) != currPlatforms.end()) {
            platformFilteredGames.push_back(filteredGames[i]);
        }
    }
    return platformFilteredGames;
}

// fills in the values for the achievment difference for every game in the filtered array
void Similar::findDifference(std::string gameName, vector<Game>& similarGames) {
    for(auto& i : similarGames) {
        if (i.name != gameName) {
            // takes the absolute value of the difference of achievementCounts, to show the games that have the closest counts
            i.achievementDifference = abs(i.achievementCount - findGame(gameName).achievementCount);
        }
    }
}
