#ifndef VIDEO_GAME_RECOMMENDER_SIMILAR_H
#define VIDEO_GAME_RECOMMENDER_SIMILAR_H
#include "Game.h"

class Similar {
public:
    vector<Game>& gamesRef; // Reference to the vector of games

    explicit Similar(vector<Game>& allGames) : gamesRef(allGames) {}
    Game findGame(string name);
    pair<unordered_set<string>, unordered_set<string>> getParameters(string gameName);
    vector<Game> extractParameters(string gameName, string gamePlatform);
    void findDifference(string gameName, vector<Game>& similarGames);
};

#endif //VIDEO_GAME_RECOMMENDER_SIMILAR_H
