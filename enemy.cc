#include <iostream>
#include "enemy.h"
#include "helper.h"
#include "floor.h"
#include "hero.h"
#include "dragon.h"
#include "dragonhoard.h"
#include "barriersuit.h"
#include "cell.h"
#include <cstdlib>
#include <vector>
#include "merchant.h"

using namespace std;

void Enemy::setHero(Hero *hero) {
    this->hero = hero; 
}

void Enemy::setFloor(Floor *floor) {
    this->floor = floor;
}

void Enemy::setCompass(bool has_compass) {
    this->hasCompass = has_compass;
}

char Enemy::getType() const {
    return this->type;
}

void Enemy::moveNext() {
    int enemy_x = getX();
    int enemy_y = getY();
    int hero_x = hero->getX();
    int hero_y = hero->getY();
    if(this->getType() == 'D') {
        Dragon *d = dynamic_cast<Dragon *> (this);
        if(d->getDragonHoard()){
            if(abs(d->getDragonHoard()->getX() - hero_x) <= 1 &&
               abs(d->getDragonHoard()->getY() - hero_y) <= 1) {
                attack();
                return;
            }
        } else if(d->getBarrierSuit()) {
            if(abs(d->getBarrierSuit()->getX() - hero_x) <= 1 &&
               abs(d->getBarrierSuit()->getY() - hero_y) <= 1) {
                attack();
                return;
            }
        }
    } else if (abs(enemy_x - hero_x) <= 1 && abs(enemy_y - hero_y) <= 1) {
        if(this->getType() == 'M') {
            Merchant *m = dynamic_cast<Merchant *> (this);
            if(m->getHostile()) {
                attack();
                return;
            }
        } else {
            attack();
            return;
        }
    }

    if (moveable) {
        vector<Cell> moveable_cells;
        for (int i = enemy_x - 1; i <= enemy_x + 1; ++i) {
            for (int j = enemy_y - 1; j <= enemy_y + 1; ++j) {
                if (i == enemy_x && j == enemy_y) {
                    continue;
                }
                Cell neighbour_cell = floor->getCell(i, j);
                if (neighbour_cell.isOccupied()) {
                    continue;
                }
                moveable_cells.emplace_back(neighbour_cell);
            }
        }
        int count_moveable = moveable_cells.size();
        int random_num = helper::random(count_moveable);
        Cell next_cell = moveable_cells[random_num];
        this->c = &this->floor->getCell(next_cell.getX(), next_cell.getY());
        this->x = next_cell.getX();
        this->y = next_cell.getY();
        this->floor->getCell(this->x, this->y).SetConcreteCell(this);
        this->floor->getCell(enemy_x, enemy_y).deleteConcrete();
    }
}

void Enemy::attack() {
    if (this->getHp() == 0) {
    // drop compass???
        return;
    }
    if (this->getType() == 'M') {
        Merchant *merchant = dynamic_cast<Merchant *>(this);
        if (merchant->getHostile() == false) return;
    }
    int miss_random = helper::random(2);
    if (miss_random == 0) {
        return;
    }
    int damage = helper::ceiling((100.00 / (100.00 + hero->getDef())) * getAtk());
    if (hero->carryBarrier()) {
        damage = helper::ceiling(damage / 2);
    }
    if (hero->getHp() <= damage) {
        damage = hero->getHp();
    }
    hero->setHp(hero->getHp() - damage);
}

Enemy::~Enemy() {
    //delete hero;
    //delete floor;
}

