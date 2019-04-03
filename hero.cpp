#include "hero.h"
#include "cell.h"
#include "ConcreteCell.h"
#include "potion.h"
#include "treasure.h"
#include "compass.h"
#include "helper.h"

using namespace std;

char Hero::GetType() const {
    return '@';
}

string Hero::getRace() const {
    return this->race;
}
        
int Hero::getGold() const {
    return this->goldNum;
}

bool Hero::carryCompass() const {
    return this->hasCompass;
}

void Hero::setRace(string race_type) {
    this->race = race_type;
}

void Hero::setMaxHp(int max_hp) {
    this->maxHp = max_hp;
}

void Hero::setGoldNum(int gold_num) {
    this->goldNum = gold_num;
}

void Hero::addBarrier() {
    this->hasBarrier = true;
}

void Hero::setFloor(Floor *f) {
    this->floor = f;
}

void Hero::move(string direction) {
    int X = getX();
    int Y = getY();
    Cell origin_cell = floor->getCell(X, Y);
    X = helper::findX(X, direction);
    Y = helper::findY(Y, direction);
    Cell new_cell = floor->getCell(X, Y);
    if (!new_cell->canMove()) { return; }
    ConcreteCell *ccell = origin_cell.GetConcreteCell();
    new_cell.SetConcreteCell(ccell);
    origin_cell.deleteConcrete();
}
        
Potion *Hero::pickPotion(string direction) {
    int X = getX();
    int Y = getY();
    X = helper::findX(X, direction);
    Y = helper::findY(Y, direction);
    Cell c = floor->getCell(X, Y);
    char cell_type = c.getCellType();
    if (cell_type == 'P') {
        ConcreteCell *conc = c.GetConcreteCell();
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
				}
				else {
					hp = maxHp;
				}
			} else {
				if (hp > 10) {
					hp -= 10;
				}
				else {
					hp = 0;
				}
			}
        } else if (potion_type == "WA") {
			if (race == "Elves") {
				atk += 5;
			} else {
				if (atk > 5) {
					atk -= 5;
				}
				else {
					atk = 0;
				}
			}
        } else if (potion_type == "WD") {
			if (race == "Elves") {
				def += 5;
			} else {
				if (def > 5) {
					def -= 5;
				}
				else {
					def = 0;
				}
			}
        }
        return potion;
    }
    return nullptr;
}
        
void Hero::pickGold(string direction) {
    int X = getX();
    int Y = getY();
    X = helper::findX(X, direction);
    Y = helper::findY(Y, direction);
    Cell c = floor->getCell(X, Y);
    char cell_type = c.getCellType();
    if (cell_type == 'G') {
        ConcreteCell *conc = c.GetConcreteCell();
        Treasure *gold = dynamic_cast<Treasure *>(conc);
		if (race == "Dwarf") {
			goldNum += 2 * gold->getValue();
		} else if (race == "Elves") {
			goldNum += gold->getValue() / 2;
		} else {
			goldNum += gold->getValue();
		}
    }
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

int Hero::attack(Enemy *enemy) {
    if (!enemy) { return 0; }
    int damage = helper::ceiling((100 / (100 + enemy->getDef())) * atk);
    if (enemy->getHp() <= damage) {
        damage = getHp();
    }
    enemy->setHp(enemy->getHp() - damage);
    return damage;
}
        
Hero::~Hero() {
    delete floor;
}

