#include "helper.h"
#include <cmath>
#include <cstdlib>
#include <fstream>

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
        result.emplace_back(eachline);
    }
    return result;
}

int helper::random(int max) {
    return rand() % max;
}

int helper::findX(int current_x, string direction) {
    if (direction == "so" || direction == "se" || direction == "sw") {
        return current_x + 1;
    } else if (direction == "ne" || direction == "nw" || direction == "no") {
        return current_x - 1;
    } else if (direction == "ea" || direction == "we") {
        return current_x;
    }
}

int helper::findY(int current_y, string direction) {
    if (direction == "ne" || direction == "se" || direction == "ea") {
        return current_y + 1;
    } else if (direction == "sw" || direction == "we" || direction == "nw") {
        return current_y - 1;
    } else if (direction == "no" || direction == "so") {
        return current_y;
    }
}

int helper::ceiling(double num) {
    int num_int = num;
    double num_decimal = num - num_int;
    int retval = num_int;
    if (num_decimal > 0) {
        ++retval;
    }
    return retval;
}


