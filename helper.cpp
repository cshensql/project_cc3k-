#include "helper.h"
using namespace std;


vector<vector<char>> helper::readMap(string filename) {
    vector<vector<char>> result;
    ifstream ifs{filename};
    string aline;
    while(getline(ifs, aline)) {
        vector<char> eachline;
        for(int i = 0; i < 79; i++) {
            eachline.push_back(aline[i]);
        }
        result.emplace_back(aline);
    }
    return result;
}

int helper::random(int max) {
    return rand() % max;
}