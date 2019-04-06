#include "hero.h"
#include "cell.h"
#include "floor.h"
#include "ConcreteCell.h"
#include "potion.h"
#include "treasure.h"
#include "compass.h"
#include "helper.h"
#include "merchant.h"
#include "barriersuit.h"
#include "dragon.h"
#include "dragonhoard.h"
#include "enemy.h"
#include <cmath>
#include <iostream>

using namespace std;

void Hero::SetType() {
    this->Type = '@';
}


char Hero::GetType() const {
    return '@';
}

string Hero::getRace() const {
    return this->race;
}

double Hero::getGold() const {
    return this->goldNum;
}

bool Hero::carryCompass() const {
    return this->hasCompass;
}

bool Hero::carryBarrier() const {
	return this->hasBarrier;
}

void Hero::setRace(string race_type) {
    this->race = race_type;
}

void Hero::setMaxHp(int max_hp) {
    this->maxHp = max_hp;
}

void Hero::setGoldNum(double gold_num) {
    this->goldNum = gold_num;
}

void Hero::addBarrier() {
    this->hasBarrier = true;
}

void Hero::setFloor(Floor *f) {
    this->floor = f;
}

void Hero::move(string direction) {
    int origin_X = getX();
    int origin_Y = getY();
    int X = helper::findX(origin_X, direction);
    int Y = helper::findY(origin_Y, direction);
    Cell new_cell = floor->getCell(X, Y);
    if (!new_cell.canMove()) return;
    ConcreteCell *conc = new_cell.GetConcreteCell();
    if (conc != nullptr && conc->GetType() == 'G') {
	bool picked = this->pickGold(new_cell);
	if (!picked) return;
    }
    this->c = &this->floor->getCell(new_cell.getX(), new_cell.getY());
    this->x = new_cell.getX();
    this->y = new_cell.getY();
    this->floor->getCell(this->x, this->y).SetConcreteCell(this);
    this->floor->getCell(origin_X, origin_Y).deleteConcrete();
}
    
Potion *Hero::pickPotion(string direction) {
    int X = getX();
    int Y = getY();
    int newX = helper::findX(X, direction);
    int newY = helper::findY(Y, direction);
    Cell c = floor->getCell(newX, newY);
    ConcreteCell *conc = c.GetConcreteCell();
    if(conc) {
        char cell_type = c.GetConcreteCell()->GetType();
        if (cell_type == 'P') {
            Potion *potion = dynamic_cast<Potion *>(conc);
            if (potion->getIsUsed()) {
                return potion;
            }
            potion->setUsed();
            string potion_type = potion->getType();
            if (potion_type == "RH") {
                if (hp + 10 < maxHp) {
                    hp += 10;
                } else {
                    hp = maxHp;
                }
            } else if (potion_type == "BA") {
                atk += 5;
            } else if (potion_type == "BD") {
                def += 5;
            } else if (potion_type == "PH") {
                if (race == "Elves") {
                    if (hp + 10 < maxHp) {
                        hp += 10;
                    } else {
                        hp = maxHp;
                    }
                } else {
                    if (hp > 10) {
                        hp -= 10;
                    } else {
                        hp = 0;
                    }
                }
            } else if (potion_type == "WA") {
                if (race == "Elves") {
                    atk += 5;
                } else {
                    if (atk > 5) {
                        atk -= 5;
                    } else {
                        atk = 0;
                    }
                }
            } else if (potion_type == "WD") {
                if (race == "Elves") {
                    def += 5;
                } else {
                    if (def > 5) {
                        def -= 5;
                    } else {
                        def = 0;
                    }
                }
            }
            this->floor->getCell(newX, newY).deleteConcrete(); //delete potion
            return potion;
        }
    }else {
        return nullptr;
    }
}
        
bool Hero::pickGold(Cell &gold_cell) {
    ConcreteCell *conc = gold_cell.GetConcreteCell();
    if (conc == nullptr || conc->GetType() != 'G') return false;
    Treasure *gold = dynamic_cast<Treasure *>(conc);
    if (!gold->isPickable()) { return false; }
    if (race == "Dwarf") {
        goldNum += 2 * gold->getValue();
    } else if (race == "Elves") {
        goldNum += gold->getValue() / 2;
    } else {
        goldNum += gold->getValue();
    }
    gold_cell.deleteConcrete();
    return true;
}
        
void Hero::pickCompass(string direction) {
    int X = getX();
    int Y = getY();
    X = helper::findX(X, direction);
    Y = helper::findY(Y, direction);
    Cell c = floor->getCell(X, Y);
    char cell_type = c.getCellType();
    if (cell_type == 'C') {
        this->hasCompass = true;
    }
}

void Hero::pickBarrierSuit(string direction) {
    int X = getX();
    int Y = getY();
    X = helper::findX(X, direction);
    Y = helper::findY(Y, direction);
    Cell c = floor->getCell(X, Y);
    char cell_type = c.getCellType();
    if (cell_type == 'B') {
        ConcreteCell *conc = c.GetConcreteCell();
        BarrierSuit *bs = dynamic_cast<BarrierSuit *>(conc);
        if (!bs->isPickable()) { return; }
        this->hasBarrier = true;
    }
}

Enemy *Hero::attackDir(string direction) {
    int X = getX();
    int Y = getY();
    X = helper::findX(X, direction);
    Y = helper::findY(Y, direction);
    Cell c = floor->getCell(X, Y);
    char cell_type = c.getCellType();
    if (cell_type == 'V' || cell_type == 'W' || cell_type == 'N' ||
    cell_type == 'M' || cell_type == 'D' || cell_type == 'X' || cell_type == 'T') {
        ConcreteCell *conc = c.GetConcreteCell();
        Enemy *enemy = dynamic_cast<Enemy *>(conc);
        return enemy;
    }
}

double Hero::attack(Enemy *enemy) {
    if (!enemy) { return 0; }
    double damage = ceil((100 / (100 + enemy->getDef())) * atk);
    //int damage = helper::ceiling((100 / (100 + enemy->getDef())) * atk);
    if (enemy->getHp() <= damage) {
        damage = getHp();
    }
    enemy->setHp(enemy->getHp() - damage);
    if (enemy->getType() == 'M') {
	Merchant *merchant = dynamic_cast<Merchant *>(enemy);
        merchant->setHostile(true);
    }
    if (!enemy->isAlive()) {
        if (enemy->getType() == 'D') {
            Dragon *dragon = dynamic_cast<Dragon *>(enemy);
            if (dragon->getDragonHoard()) { dragon->getDragonHoard()->setPickable(true); }
            if (dragon->getBarrierSuit()) { dragon->getBarrierSuit()->setPickable(true); }
        }
        double drop_gold = enemy->dropGold();
        if (race == "Dwarf") {
            goldNum += 2 * drop_gold;
        } else if (race == "Elves") {
            goldNum += drop_gold / 2;
        } else {
            goldNum += drop_gold;
        }

        // TO-DO: drop compass ???


    }
    return damage;
}
        
Hero::~Hero() {
    delete floor;
}

