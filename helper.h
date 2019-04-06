#ifndef _HELPER_H
#define _HELPER_H

#include <string>
#include <vector>

class helper {
public:
    static std::vector<std::vector<char>> readMap(std::string filename);
    static int random(int max);
    static int findX(int current_x, std::string direction);
    static int findY(int current_y, std::string direction);
//    static int ceiling(double num);
};


#endif //_HELPER_H
