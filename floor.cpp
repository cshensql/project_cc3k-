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
    for(Potion *p : potion) {
        if(p) delete p;
    }
    for(Treasure *t : treasure) {
        if(t) delete t;
    }
    for(Chamber *c : chamber) {
        if(c) delete c;
    }
    cells.clear();
    enemies.clear();
    potion.clear();
    treasure.clear();
    chamber.clear();
}


void Floor::init() {

}

void Floor::initHero() {

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

