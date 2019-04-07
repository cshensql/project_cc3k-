#include <iostream>
#include "floor.h"
#include "potion.h"
#include "helper.h"
#include "treasure.h"
#include "normal.h"
#include "small.h"
#include "merchanthoard.h"
#include "dragonhoard.h"
#include "barriersuit.h"
#include "compass.h"
#include "goblin.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "merchant.h"
#include "dragon.h"
#include "phoenix.h"
#include "chamber.h"
#include "hero.h"
using namespace std;

Floor::Floor(Hero *hero): hero{hero} {}

Floor::~Floor() {
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
    clear();
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
            eachline.emplace_back(Cell(map[i][j], i, j));
        }
        this->cells.push_back(eachline);
    }

    //init hero
    int n = helper::random(5);
    initHero(n);

    //init stair
    while(true) {
        int m = helper::random(5);
        if(m != n) {
            initStairs(m);
            break;
        }
    }

    //init enemies except dragon
    initEnemies();

    //init treasure and dragon
    initTreasures();

    //init barrier suit
    initBarrierSuit();

    //init potions
    initPotions();
}

void Floor::initHero(int chamberIndex) {
    int index, x, y = 0;
    int chamberSize = this->chambers[chamberIndex]->getSize();
    while(true) {
        index = helper::random(chamberSize);
        x = this->chambers[chamberIndex]->getCells()[index].getX();
        y = this->chambers[chamberIndex]->getCells()[index].getY();
        if(!this->getCell(x, y).isOccupied()) {
            this->hero->setX(x);
            this->hero->setY(y);
            this->hero->SetCell(&this->getCell(x, y));
            this->hero->SetType();
            this->getCell(x, y).SetConcreteCell(this->hero);
            break;
        }
    }
}

void Floor::initEnemies() {
    int index = 0;
    int x = 0;
    int y = 0;
    int chamberIndex = 0;
    int chamberSize = 0;
    int enemyType = 0;
    int compass = 0;

    for(int i = 0; i < 20; i++) {
        while(true) {
            chamberIndex = helper::random(5);
            chamberSize = this->chambers[chamberIndex]->getSize();
            index = helper::random(chamberSize);
            x = this->chambers[chamberIndex]->getCells()[index].getX();
            y = this->chambers[chamberIndex]->getCells()[index].getY();
            Enemy *e;
            if(!this->getCell(x, y).isOccupied()) {
                enemyType = helper::random(18);
                if(enemyType == 0 || enemyType == 1 || enemyType == 2 || enemyType == 3) {
                    e = new Werewolf();
                } else if(enemyType == 4 || enemyType == 5 || enemyType == 6) {
                    e = new Vampire();
                } else if(enemyType == 7 || enemyType == 8 || enemyType == 9 || enemyType == 10 || enemyType == 11) {
                    e = new Goblin();
                } else if(enemyType == 12 || enemyType == 13) {
                    e = new Troll();
                } else if(enemyType == 14 || enemyType == 15) {
                    e = new Phoenix();
                } else if(enemyType == 16 || enemyType == 17) {
                    e = new Merchant();
                }

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
    compass = helper::random(20);
    this->enemies[compass]->setCompass(true);
    //Compass *c = new Compass();
    //c->setHolder(this->enemies[compass]);
    cout << "Compass: " << this->enemies[compass]->getX() << ", " << this->enemies[compass]->getY() << endl;
}


void Floor::initPotions() {
    int index = 0;
    int x = 0;
    int y = 0;
    int chamberIndex = 0;
    int chamberSize = 0;
    int potionType = 0;
    string potionName;

    for(int i = 0; i < 10; i++) {
        while(true) {
            chamberIndex = helper::random(5);
            chamberSize = this->chambers[chamberIndex]->getSize();
            index = helper::random(chamberSize);
            x = this->chambers[chamberIndex]->getCells()[index].getX();
            y = this->chambers[chamberIndex]->getCells()[index].getY();
            if(!this->getCell(x, y).isOccupied()) {
                potionType = helper::random(6);
                if(potionType == 0) {
                    potionName = "RH";
                } else if(potionType == 1) {
                    potionName = "BA";
                } else if(potionType == 2) {
                    potionName = "BD";
                } else if(potionType == 3) {
                    potionName = "PH";
                } else if(potionType == 4) {
                    potionName = "WA";
                } else if(potionType == 5) {
                    potionName = "WD";
                }

                Potion *p = new Potion(potionName);
                p->setX(x);
                p->setY(y);
                this->potions.push_back(p);
                this->getCell(x, y).SetConcreteCell(p);
                p->SetCell(&this->getCell(x, y));
                break;
            }
        }
    }
}


void Floor::initTreasures() {
    int index = 0;
    int x = 0;
    int y = 0;
    int chamberIndex = 0;
    int chamberSize = 0;
    int treasureType = 0;
    string treasureName;

    for(int i = 0; i < 10; i++) {
        while(true) {
            chamberIndex = helper::random(5);
            chamberSize = this->chambers[chamberIndex]->getSize();
            index = helper::random(chamberSize);
            x = this->chambers[chamberIndex]->getCells()[index].getX();
            y = this->chambers[chamberIndex]->getCells()[index].getY();
            Treasure *t;
            if(!this->getCell(x, y).isOccupied()) {
                treasureType = helper::random(8);
                if(treasureType == 0 || treasureType == 1 || treasureType == 2 || treasureType == 3 || treasureType == 4) {
                    treasureName = "normal";
                    t = new Normal();
                } else if(treasureType == 5) {
                    treasureName = "dragon hoard";
                    t = new DragonHoard();
                } else if(treasureType == 6 || treasureType == 7) {
                    treasureName = "small hoard";
                    t = new Small();
                }

                t->setX(x);
                t->setY(y);
                t->SetCell(&this->getCell(x, y));
                this->treasures.push_back(t);
                this->getCell(x,y).SetConcreteCell(t);

                //generate a dragon next to the dragon hoard
                if(treasureName == "dragon hoard") {
                    DragonHoard *dh = dynamic_cast<DragonHoard *> (t);
                    bool dragon_born = false;
                    while(!dragon_born) {
                        vector<string> directions;
                        directions.emplace_back("no");
                        directions.emplace_back("so");
                        directions.emplace_back("ea");
                        directions.emplace_back("we");
                        directions.emplace_back("ne");
                        directions.emplace_back("nw");
                        directions.emplace_back("se");
                        directions.emplace_back("sw");
                        int dragon = helper::random(8); //0-7
                        int count = 0;
                        int newx = 0;
                        int newy = 0;
                        for (string s : directions) {
                            newx = helper::findX(x, s);
                            newy = helper::findY(y, s);
                            if(count == dragon && !this->getCell(newx, newy).isOccupied()) {
                                Enemy *e = new Dragon();
                                e->setX(newx);
                                e->setY(newy);
                                e->setHero(this->hero);
                                e->setFloor(this);
                                this->getCell(newx,newy).SetConcreteCell(e);
                                e->SetCell(&this->getCell(newx, newy));
                                this->enemies.push_back(e);
                                Dragon *d = dynamic_cast<Dragon *> (e);
                                d->setDragonHoard(dh);
                                dragon_born = true;
                                break;
                            }
                            count++;
                        }
                    }
                }
                break;
            } else {
                continue;
            }
        }
    }
}


void Floor::initBarrierSuit() {
    int floorNum = 0;
    int chamberIndex = 0;
    int chamberSize = 0;
    int index = 0;
    int x = 0;
    int y = 0;
    floorNum = helper::random(5);
    while(true) {
        if(this->currentFloor == (floorNum + 1)) {
            chamberIndex = helper::random(5);
            chamberSize = this->chambers[chamberIndex]->getSize();
            index = helper::random(chamberSize);
            x = this->chambers[chamberIndex]->getCells()[index].getX();
            y = this->chambers[chamberIndex]->getCells()[index].getY();
            if(!this->getCell(x, y).isOccupied()) {
                Item *i = new BarrierSuit();
                BarrierSuit *bs = dynamic_cast<BarrierSuit *> (i);
                bs->setX(x);
                bs->setY(y);
                bs->SetCell(&this->getCell(x, y));
                this->barrierSuit = bs;
                this->getCell(x,y).SetConcreteCell(bs);

                //generate a dragon next to the barriersuit
                bool dragon_born = false;
                while(!dragon_born) {
                    vector<string> directions;
                    directions.emplace_back("no");
                    directions.emplace_back("so");
                    directions.emplace_back("ea");
                    directions.emplace_back("we");
                    directions.emplace_back("ne");
                    directions.emplace_back("nw");
                    directions.emplace_back("se");
                    directions.emplace_back("sw");
                    int dragon = helper::random(8); //0-7
                    int count = 0;
                    int newx = 0;
                    int newy = 0;
                    for (string s : directions) {
                        newx = helper::findX(x, s);
                        newy = helper::findY(y, s);
                        if(count == dragon && !this->getCell(newx, newy).isOccupied()) {
                            Enemy *e = new Dragon();
                            e->setX(newx);
                            e->setY(newy);
                            e->setHero(this->hero);
                            e->setFloor(this);
                            this->getCell(newx,newy).SetConcreteCell(e);
                            e->SetCell(&this->getCell(newx, newy));
                            this->enemies.push_back(e);
                            Dragon *d = dynamic_cast<Dragon *> (e);
                            d->setBarrierSuit(bs);
                            dragon_born = true;
                            break;
                        }
                        count++;
                    }
                }
                break;
            } else {
                continue;
            }
        } else {
            return;
        }
    }
}


void Floor::initStairs(int chamberIndex) {
    int index, x, y = 0;
    int chamberSize = this->chambers[chamberIndex]->getSize();
    while(true) {
        index = helper::random(chamberSize);
        x = this->chambers[chamberIndex]->getCells()[index].getX();
        y = this->chambers[chamberIndex]->getCells()[index].getY();
        if(!this->getCell(x, y).isOccupied()) {
            this->getCell(x, y).setCell('\\');
            this->getCell(x, y).SetConcreteCell(nullptr);
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
            double goldNum = enemies[i]->dropGold();
            enemies[i]->GetCell()->deleteConcrete();
            Treasure *t;
            if(goldNum == 4) {
                t = new MerchantHoard();
                enemies[i]->GetCell()->SetConcreteCell(t);
                t->SetCell(&this->getCell(enemies[i]->getX(), enemies[i]->getY()));
                this->treasures.push_back(t);
            }
	    if (enemies[i]->getCompass()) {
                Compass *cp = new Compass();
                enemies[i]->GetCell()->SetConcreteCell(cp);
                cp->SetCell(&this->getCell(enemies[i]->getX(), enemies[i]->getY()));
            }
            delete enemies[i];
            enemies[i] = nullptr;
            break;
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

