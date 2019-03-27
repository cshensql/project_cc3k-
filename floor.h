#ifndef _FLOOR_H
#define _FLOOR_H

#include <vector>
#include "cell.h"

class Floor {
    Hero *hero;
    int currentFloor;
    static const int col = 79;
    static const int row = 30;
    std::vector<std::vector<Cell>> cells;
    std::vector<Enemy *>;
    std::vector<Potion *>;
    std::vector<Treasure *>;
    std::vector<Chamber *>;
public:
    Floor(Hero *hero);
    ~Floor();
    void clear();
    void init();
    void initHero();
    void initEnemies();
    void initPotions();
    void initTreasures();
    void updataCurFloor();
    int getCurrentFloor();
    void nextTurn();
    Cell &getCell(int x, int y);
};


#endif //_FLOOR_H
