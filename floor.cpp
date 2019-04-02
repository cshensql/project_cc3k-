#include <iostream>
#include "floor.h"
#include "potion.h"
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

void Floor::clear() {
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

// generate random chamber for hero, stairs
void Floor::init() {
    vector<vector<char>> map;
    vector<vector<char>> chamberMap;
    map = helper::readMap("map.txt");
    chamberMap = helper::readMap("chamberInd.txt");

    // init chambers
    this->chambers = {new Chamber(), new Chamber(), new Chamber(), new Chamber(), new Chamber()};
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 79; j++) {
            if(chamberMap[i][j] == '0') {
                this->chambers[0]->addToChamber(Cell('.', i, j));
            } else if(chamberMap[i][j] == '1') {
                this->chambers[1]->addToChamber(Cell('.', i, j));
            } else if(chamberMap[i][j] == '2') {
                this->chambers[2]->addToChamber(Cell('.', i, j));
            } else if(chamberMap[i][j] == '3') {
                this->chambers[3]->addToChamber(Cell('.', i, j));
            } else if(chamberMap[i][j] == '4') {
                this->chambers[4]->addToChamber(Cell('.', i, j));
            }
        }
    }


    //init cells
    for(int i = 0; i < 25; i++) {
        vector<Cell> eachline;
        for (int j = 0; j < 79; j++) {
            eachline.push_back(Cell(map[i][j], i, j));
        }
        this->cells.push_back(eachline);
    }

    //init hero
    int n = helper::random(5);
    initHero(n);

    //init stair
    while(1) {
        int m = helper::random(5);
        if(m != n) {
            initStairs(m);
            break;
        }
    }

    //init enemies
    initEnemies();

    //init treasure
    initTreasures();

    //init potions
    initPotions();
}

void Floor::initHero(int chamberIndex) {
    int index, x, y = 0;
    int chamberSize = this->chambers[chamberIndex]->getSize();
    while(1) {
        index = helper::random(chamberSize);
        x = this->chambers[chamberIndex]->getCells()[index].getX();
        y = this->chambers[chamberIndex]->getCells()[index].getY();
        if(!this->getCell(x, y).isOccupied()) {
            this->hero->setX(x);
            this->hero->setY(y);
            this->getCell(x, y).SetConcreteCell(this->hero);
            this->hero->SetCell(&this->getCell(x, y));
            break;
        }
    }
}

void Floor::initEnemies() {
    int index, x, y, chamberIndex, chamberSize, enemyType, compass = 0;
    char enemyName;
    bool has_compass;

    for(int i = 0; i < 20; i++) {
        while(true) {
            chamberIndex = helper::random(5);
            index = helper::random(chamberSize);
            chamberSize = this->chambers[chamberIndex]->getSize();
            x = this->chambers[chamberIndex]->getCells()[index].getX();
            y = this->chambers[chamberIndex]->getCells()[index].getY();
            if(!this->getCell(x, y).isOccupied()) {
                enemyType = helper::random(18);
                switch(enemyType) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        enemyName = 'W';
                    case 4:
                    case 5:
                    case 6:
                        enemyName = 'V';
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        enemyName = 'N';
                    case 12:
                    case 13:
                        enemyName = 'T';
                    case 14:
                    case 15:
                        enemyName = 'X';
                    case 16:
                    case 17:
                        enemyName = 'M';
                }
                compass = helper::random(20);
                if(compass == 0) {
                    has_compass = true;
                } else {
                    has_compass = false;
                }
                Enemy *e = Enemy::createEnemy(enemyName, has_compass);
                e->setX(x);
                e->setY(y);
                e->setHero(this->hero);
                e->setFloor(this);
                this->enemies.push_back(e);
                this->getCell(x,y).SetConcreteCell(e);
                e->SetCell(&this->getCell(x, y));
                break;
            }
        }
    }
}


void Floor::initPotions() {
    int index, x, y, chamberIndex, chamberSize, potionType = 0;
    string potionName;

    for(int i = 0; i < 10; i++) {
        while(true) {
            chamberIndex = helper::random(5);
            index = helper::random(chamberSize);
            chamberSize = this->chambers[chamberIndex]->getSize();
            x = this->chambers[chamberIndex]->getCells()[index].getX();
            y = this->chambers[chamberIndex]->getCells()[index].getY();
            if(!this->getCell(x, y).isOccupied()) {
                potionType = helper::random(6);
                switch(potionType) {
                    case 0:
                        potionName = "RH";
                    case 1:
                        potionName = "BA";
                    case 2:
                        potionName = "BD";
                    case 3:
                        potionName = "PH";
                    case 4:
                        potionName = "WA";
                    case 5:
                        potionName = "WD";
                }
                Potion *p = new Potion(potionName);
                p->setX(x);
                p->setY(y);
                this->potions.push_back(p);
                this->getCell(x,y).SetConcreteCell(p);
                p->SetCell(&this->getCell(x, y));
                break;
            }
        }
    }
}


void Floor::initTreasures() {
    int index, x, y, chamberIndex, chamberSize, treasureType = 0;
    string treasureName;

    for(int i = 0; i < 10; i++) {
        while(true) {
            chamberIndex = helper::random(5);
            index = helper::random(chamberSize);
            chamberSize = this->chambers[chamberIndex]->getSize();
            x = this->chambers[chamberIndex]->getCells()[index].getX();
            y = this->chambers[chamberIndex]->getCells()[index].getY();
            if(!this->getCell(x, y).isOccupied()) {
                treasureType = helper::random(8);
                switch(treasureType) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        treasureName = "normal";
                    case 5:
                        treasureName = "dragon hoard";
                    case 6:
                    case 7:
                        treasureName = "small hoard";
                }
                Treasure *t = Treasure::createTreasure(treasureName);
                t->setX(x);
                t->setY(y);
                this->treasures.push_back(t);
                this->getCell(x,y).SetConcreteCell(t);
                t->SetCell(&this->getCell(x, y));
                break;
            }
        }
    }
}


void Floor::initStairs(int chamberIndex) {
    int index, x, y = 0;
    int chamberSize = this->chambers[chamberIndex]->getSize();
    while(1) {
        index = helper::random(chamberSize);
        x = this->chambers[chamberIndex]->getCells()[index].getX();
        y = this->chambers[chamberIndex]->getCells()[index].getY();
        if(!this->getCell(x, y).isOccupied()) {
            this->getCell(x, y).setCell('\\');
            break;
        }
    }
}

void Floor::updateCurFloor() {
    this->currentFloor++;
}


int Floor::getCurrentFloor() {
    return this->currentFloor;
}

Hero *Floor::getHero() {
    return this->hero;
}

void Floor::nextTurn() {
    for(int i = 0; i < this->enemies.size(); i++) {
        if(enemies[i] && !enemies[i]->isAlive()) {
            enemies[i]->GetCell()->deleteConcrete();
            int goldNum = enemies[i]->dropGold();
            if(goldNum == 1) {
                Treasure *t = Treasure::CreateTreasure("normal");
            } else if(goldNum == 2) {
                Treasure *t = Treasure::CreateTreasure("small horde");
            } else if(goldNum == 4) {
                Treasure *t = Treasure::CreateTreasure("merchant hoard");
            } else if(goldNum == 6) {
                Treasure *t = Treasure::CreateTreasure("dragon hoard");
            }
            enemies[i]->GetCell()->SetConcreteCell(t);
            this->treasures.push_back(t);
            delete enemies[i];
            enemies[i] = nullptr;
        }
    }

    for(Enemy *e : this->enemies) {
        if(e) {
            e->moveNext();
        }
    }
}


Cell &Floor::getCell(int x, int y) {
    return this->cells[x][y];
}

