#ifndef _HELPER_H
#define _HELPER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

class helper {
    static std::vector<std::vector<char>> readMap(std::string filename);
    static int random(int max);
};


#endif //_HELPER_H
