#include <iostream>
#include "floor.h"
#include "helper.h"
using namespace std;

Floor::Floor(Hero *hero): hero{hero} {}

Floor::~Floor() {
    delete hero;
    for(Enemy *e : enemies) {
        if(e) delete e;
    }
    for(Potion *p : potions) {
        if(p) delete p;
    }
    for(Treasure *t : treasures) {
        if(t) delete t;
    }
    for(Chamber *c : chambers) {
        if(c) delete c;
    }
    cells.clear();
    enemies.clear();
    potions.clear();
    treasures.clear();
    chambers.clear();
}

// generate random chamber for hero
void Floor::init() {

}

void Floor::initHero(int chamberInd) {
    int index, x, y = 0;
    int chamberSize = this->chambers[chamberInd]->getSize();
    while(1) {
        index = helper::random(chamberSize);
        x = this->chambers[chamberInd]->getCells()[index].getX();
        y = this->chambers[chamberInd]->getCells()[index].getY();
        if(!this->getCell(x, y).isOccupied()) {
            this->hero->
        }
    }
}

void Floor::initEnemies() {

}

void Floor::initPotions() {

}

void Floor::initTreasures() {

}

void updataCurFloor() {

}


int getCurrentFloor() {

}

void nextTurn() {

}


Cell &getCell(int x, int y) {

}

