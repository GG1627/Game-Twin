#include "Game.h"

class SortingAlgorithms {
public:
    // main sorting algorithms
    void cocktailSortMetacritic(vector<Game>& games, int size);
    void quickSortMetacritic(vector<Game>& games, int low, int high);
    int partitionMetacritic(vector<Game>& games, int low, int high);

    // optional sorting algorithms
    void cocktailSortAchievementCount(vector<Game>& games, int size);
    void quickSortAchievmentCount(vector<Game>& games, int low, int high);
    int partitionAchievmentCount(vector<Game>& games, int low, int high);

    void cocktailSortSuggestionsCount(vector<Game>& games, int size);
    void quickSortSuggestionsCount(vector<Game>& games, int low, int high);
    int partitionSuggestionsCount(vector<Game>& games, int low, int high);

};
