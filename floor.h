#ifndef _FLOOR_H
#define _FLOOR_H

#include <iostream>
#include <vector>
#include "cell.h"
#include "chamber.h"
#include "hero.h"

class Enemy;
class Potion;
class Treasure;


class Floor {
    Hero *hero;
    int currentFloor;
    static const int col = 79;
    static const int row = 30;
    std::vector<std::vector<Cell>> cells;
    std::vector<Enemy *> enemies;
    std::vector<Potion *> potions;
    std::vector<Treasure *> treasures;
    std::vector<Chamber *> chambers;
public:
    Floor(Hero *hero);
    ~Floor();
    void init();
    void initHero(int chamberInd);
    void initEnemies();
    void initPotions();
    void initTreasures();
    void initStairs(int chamberIndex);
    void updataCurFloor();
    int getCurrentFloor();
    void nextTurn();
    Cell &getCell(int x, int y);
};


#endif //_FLOOR_H
