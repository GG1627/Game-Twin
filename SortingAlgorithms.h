#include "Game.h"

class SortingAlgorithms {
public:
    // sort by Metacritic algorithms
    void cocktailSortMetacritic(vector<Game>& games, int size);
    void quickSortMetacritic(vector<Game>& games, int low, int high);
    int partitionMetacritic(vector<Game>& games, int low, int high);

    // sort by Metacritic algorithms
    void cocktailSortAchievementCount(vector<Game>& games, int size);
    void quickSortAchievmentCount(vector<Game>& games, int low, int high);
    int partitionAchievmentCount(vector<Game>& games, int low, int high);

    // sort by Metacritic algorithms
    void cocktailSortSuggestionsCount(vector<Game>& games, int size);
    void quickSortSuggestionsCount(vector<Game>& games, int low, int high);
    int partitionSuggestionsCount(vector<Game>& games, int low, int high);

};
