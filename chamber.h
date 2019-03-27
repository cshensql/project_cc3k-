#ifndef _CHAMBER_H
#define _CHAMBER_H

#include <vector>
#include "cell.h"

class Chamber {
    std::vector<Cell> cells;
    bool hasHero = false;
    bool hasStair = false;
public:
    Chamber();
    ~Chamber();
    std::vector<Cell> getCells();
    int getSize();
    void addToChamber(Cell c);
};

#endif //_CHAMBER_H
