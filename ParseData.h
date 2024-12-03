#ifndef VIDEO_GAME_RECOMMENDER_PARSEDATA_H
#define VIDEO_GAME_RECOMMENDER_PARSEDATA_H
#include "Game.h"

class ParseData {
    public:
        void ParseCSVFile();
        vector<Game> games;
};


#endif //VIDEO_GAME_RECOMMENDER_PARSEDATA_H
