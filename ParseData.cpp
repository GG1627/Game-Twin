#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Game.h"
#include "ParseData.h"

using namespace std;

void ParseData::ParseCSVFile() {
    ifstream file("Data/game_info.csv");
    if(!file.is_open()){
        //cout << "File could not be opened BAD" << endl;
    }
    else{
        //cout << "File opened successfully GOOD" << endl;
    }

    string line;
    getline(file, line);  // skip the first line with all categories

    while(getline(file, line)){
        stringstream ss(line);

        // target values
        string name, metacriticStr, ratingStr, genres;
        double metacritic, rating;
        int achievementCount,  suggestionsCount;

        // other values
        string id;
        string slug;
        getline(ss, id, ',');
        getline(ss, slug, ',');

        getline(ss, name, ',');  // target value
        getline(ss, metacriticStr, ',');  // target value

        string released;
        string tba;
        string updated;
        string website;
        getline(ss, released, ',');
        getline(ss, tba, ',');
        getline(ss, updated, ',');
        getline(ss, website, ',');

        getline(ss, ratingStr, ',');  // target value

        string rating_top;
        string playtime;
        string achievements_count;
        string ratings_count;
        string suggestions_count_str;
        string game_series_count;
        string reviews_count;
        string platforms;
        string developers;
        getline(ss, rating_top, ',');
        getline(ss, playtime, ',');
        getline(ss, achievements_count, ',');
        getline(ss, ratings_count, ',');
        getline(ss, suggestions_count_str, ',');
        getline(ss, game_series_count, ',');
        getline(ss, reviews_count, ',');
        getline(ss, platforms, ',');
        getline(ss, developers, ',');

        getline(ss, genres, ',');  // target value

        string publishers;
        string esrb_rating;
        string added_status_yet;
        string added_status_owned;
        string added_status_beaten;
        string added_status_toplay;
        string added_status_dropped;
        string added_status_playing;
        getline(ss, publishers, ',');
        getline(ss, esrb_rating, ',');
        getline(ss, added_status_yet, ',');
        getline(ss, added_status_owned, ',');
        getline(ss, added_status_beaten, ',');
        getline(ss, added_status_toplay, ',');
        getline(ss, added_status_dropped, ',');
        getline(ss, added_status_playing, ',');

//        debugging
//        cout << "name: " << name << ", rating: " << ratingStr << ", metacriticStr: '" << metacriticStr << "', ratingStr: '" << ratingStr << "'" << endl;

        if(metacriticStr.empty()){
            metacriticStr = "0";
        }
        if(ratingStr.empty()){
            ratingStr = "0";
        }
        if(achievements_count.empty()){
            achievements_count = "0";
        }
        if(suggestions_count_str.empty()){
            suggestions_count_str = "0";
        }

        metacritic = stoi(metacriticStr);
        rating = stod(ratingStr);
        achievementCount = stoi(achievements_count);
        //cout << "Suggestion Count: " << suggestions_count_str << endl;
        suggestionsCount = stoi(suggestions_count_str);


        if(metacriticStr != "0") {
            unordered_set<string> genresSet;
            unordered_set<string> platformsSet;
            unordered_set<string> publishersSet;
            size_t start = 0, end;

            // Extract genres
            while ((end = genres.find("||", start)) != string::npos) {
                genresSet.insert(genres.substr(start, end - start)); // Extract genre
                start = end + 2;  // Move past "||"
            }
            genresSet.insert(genres.substr(start));  // Add the last genre

            start = 0;  // Reset the start position for platforms

            // Extract platforms (assuming platforms are also separated by "||")
            while ((end = platforms.find("||", start)) != string::npos) {
                platformsSet.insert(platforms.substr(start, end - start)); // Extract platform
                start = end + 2;  // Move past "||"
            }
            platformsSet.insert(platforms.substr(start));  // Add the last platform

            // Add the game object with both genres and platforms sets
            games.emplace_back(name, metacritic, rating, suggestionsCount, achievementCount, genresSet, platformsSet);
        }

    }
    file.close();
}

