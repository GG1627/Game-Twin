#ifndef VIDEO_GAME_RECOMMENDER_SIMILAR_H
#define VIDEO_GAME_RECOMMENDER_SIMILAR_H
#include "Game.h"

class Similar {
    public:
    vector<Game>& gamesRef; // Reference to the vector of games

    explicit Similar(vector<Game>& allGames) : gamesRef(allGames) {}

    const unordered_set<string>& getGenres(const string& gameName) const {
        for(const auto& game : gamesRef) {
            if(game.name == gameName) {
                return game.gameGenres;
            }
        }
        throw runtime_error("Game not found!");
    }

    const unordered_set<string>& getPlatforms(const string& gameName) const {
        for(const auto& game : gamesRef) {
            if(game.name == gameName) {
                return game.gamePlatforms;
            }
        }
        throw runtime_error("Game not found!");
    }


    vector<Game> extractGenre(const string& gameName);
    vector<Game> extractPlatform(const string& gamePlatform, vector<Game> filteredGames);
};


#endif //VIDEO_GAME_RECOMMENDER_SIMILAR_H

