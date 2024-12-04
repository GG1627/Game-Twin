#include "Similar.h"

Game Similar::findGame(string name){
    for(const auto& game : gamesRef) {
        if(game.name == name) {
            return game;
        }
    }
    throw runtime_error("Game not found!");
}

pair<unordered_set<string>, unordered_set<string>> Similar::getParameters(string gameName) {
    return {findGame(gameName).gameGenres, findGame(gameName).gamePlatforms};
}

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

void Similar::findDifference(std::string gameName, vector<Game>& similarGames) {
    for(auto& i : similarGames) {
        if (i.name != gameName) {
            i.achievementDifference = abs(i.achievementCount - findGame(gameName).achievementCount);
        }
    }
}