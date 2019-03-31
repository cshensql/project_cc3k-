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

int helper::findX(int current_x, string direction) {
    if (direction == "ea" || direction == "ne" || direction == "se") {
        return current_x + 1;
    } else if (direction == "we" || direction == "nw" || direction == "sw") {
        return current_x - 1;
    } else if (direction == "no" || direction == "so") {
        return current_x;
    }
}

int helper::findY(int current_y, string direction) {
    if (direction == "no" || direction == "ne" || direction == "nw") {
        return current_y + 1;
    } else if (direction == "so" || direction == "se" || direction == "sw") {
        return current_y - 1;
    } else if (direction == "ea" || direction == "we") {
        return current_y;
    }
}
