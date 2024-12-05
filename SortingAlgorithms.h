#include "Game.h"

class SortingAlgorithms {
public:
    // metacritic sorts: both cocktail and quick sort
    void cocktailSortMetacritic(vector<Game>& games, int size);
    void quickSortMetacritic(vector<Game>& games, int low, int high);
    int partitionMetacritic(vector<Game>& games, int low, int high);

    // Achievement Count sorts: both cocktail and quick sort
    void cocktailSortAchievementCount(vector<Game>& games, int size);
    void quickSortAchievmentCount(vector<Game>& games, int low, int high);
    int partitionAchievmentCount(vector<Game>& games, int low, int high);

    // Suggestion Count sorts: both cocktail and quick sort
    void cocktailSortSuggestionsCount(vector<Game>& games, int size);
    void quickSortSuggestionsCount(vector<Game>& games, int low, int high);
    int partitionSuggestionsCount(vector<Game>& games, int low, int high);
};
