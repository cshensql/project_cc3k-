#ifndef _FLOOR_H
#define _FLOOR_H

#include <iostream>
#include <vector>
#include "cell.h"
#include "chamber.h"
#include "hero.h"
#include "barriersuit.h"

class Enemy;
class Potion;
class Treasure;

class Floor {
    Hero *hero;
    int currentFloor = 1;
    static const int col = 79;
    static const int row = 30;
    BarrierSuit *barrierSuit;
    std::vector<std::vector<Cell>> cells;
    std::vector<Enemy *> enemies;
    std::vector<Potion *> potions;
    std::vector<Treasure *> treasures;
    std::vector<Chamber *> chambers;
public:
    Floor(Hero *hero);
    ~Floor();
    void clear();
    void init();
    void initHero(int chamberInd);
    void initEnemies();
    void initPotions();
    void initTreasures();
    void initBarrierSuit();
    void initStairs(int chamberIndex);
    void updateCurFloor();
    int getCurrentFloor();
    Hero *getHero();
    void nextTurn();
    Cell &getCell(int x, int y);
};


#endif //_FLOOR_H
