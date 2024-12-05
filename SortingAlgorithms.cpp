#include "SortingAlgorithms.h"
#include <utility>
using namespace std;

//cocktail sorts cited from geeksforgeeks.org
void SortingAlgorithms::cocktailSortMetacritic(vector<Game>& games, int size) {
    {
        bool swapped = true;
        int start = 0;
        int end = size - 1;

        while (swapped) {
            swapped = false;

            for (int i = start; i < end; ++i) {
                if (games[i].metacritic < games[i + 1].metacritic) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
                break;
            swapped = false;
            --end;

            for (int i = end - 1; i >= start; --i) {
                if (games[i].metacritic < games[i + 1].metacritic) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            ++start;
        }
    }
};

void SortingAlgorithms::cocktailSortAchievementCount(vector<Game>& games, int size) {
    {
        bool swapped = true;
        int start = 0;
        int end = size - 1;

        while (swapped) {
            swapped = false;

            for (int i = start; i < end; ++i) {
                if (games[i].achievementDifference > games[i + 1].achievementDifference) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
                break;
            swapped = false;
            --end;

            for (int i = end - 1; i >= start; --i) {
                if (games[i].achievementDifference > games[i + 1].achievementDifference) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            ++start;
        }
    }
};

void SortingAlgorithms::cocktailSortSuggestionsCount(vector<Game> &games, int size) {
    {
        bool swapped = true;
        int start = 0;
        int end = size - 1;

        while (swapped) {
            swapped = false;

            for (int i = start; i < end; ++i) {
                if (games[i].suggestionsCount < games[i + 1].suggestionsCount) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
                break;
            swapped = false;
            --end;

            for (int i = end - 1; i >= start; --i) {
                if (games[i].suggestionsCount < games[i + 1].suggestionsCount) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            ++start;
        }
    }
};

// quicksorts cited from aman lecture slides (each sort has a partition as well)
void SortingAlgorithms::quickSortMetacritic(vector<Game>& games, int low, int high) {
    if (low < high)
    {
        int pivot = partitionMetacritic(games, low, high);
        quickSortMetacritic(games, low, pivot - 1);
        quickSortMetacritic(games, pivot + 1, high);
    }
}

int SortingAlgorithms::partitionMetacritic(vector<Game> &games, int low, int high) {
    double pivot = games[low].metacritic;
    int up = low, down = high;

    while(up < down)
    {
        for (int j = up; j < high; j++)
        {
            if (games[up].metacritic > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--) {
            if(games[down].metacritic < pivot)
                break;
            down--;
        }
        if (up < down)
            swap(games[up], games[down]);
    }
    swap(games[low], games[down]);
    return down;
}

void SortingAlgorithms::quickSortAchievmentCount(vector<Game> &games, int low, int high) {
    if (low < high)
    {
        int pivot = partitionAchievmentCount(games, low, high);
        quickSortAchievmentCount(games, low, pivot - 1);
        quickSortAchievmentCount(games, pivot + 1, high);
    }
}

int SortingAlgorithms::partitionAchievmentCount(vector<Game> &games, int low, int high) {
    double pivot = games[low].achievementDifference;
    int up = low, down = high;

    while(up < down)
    {
        for (int j = up; j < high; j++)
        {
            if (games[up].achievementDifference > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--) {
            if(games[down].achievementDifference < pivot)
                break;
            down--;
        }
        if (up < down)
            swap(games[up], games[down]);
    }
    swap(games[low], games[down]);
    return down;
}

void SortingAlgorithms::quickSortSuggestionsCount(vector<Game> &games, int low, int high) {
    if (low < high)
    {
        int pivot = partitionSuggestionsCount(games, low, high);
        quickSortSuggestionsCount(games, low, pivot - 1);
        quickSortSuggestionsCount(games, pivot + 1, high);
    }
}

int SortingAlgorithms::partitionSuggestionsCount(vector<Game> &games, int low, int high) {
    double pivot = games[low].suggestionsCount;
    int up = low, down = high;

    while(up < down)
    {
        for (int j = up; j < high; j++)
        {
            if (games[up].suggestionsCount > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--) {
            if(games[down].suggestionsCount < pivot)
                break;
            down--;
        }
        if (up < down)
            swap(games[up], games[down]);
    }
    swap(games[low], games[down]);
    return down;
}
