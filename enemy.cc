#include "enemy.h"
#include "helper.h"
#include "floor.h"
#include "hero.h"
#include "cell.h"
#include <cstdlib>
#include <vector>
#include <cmath>

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
	if (abs(enemy_x - hero_x) <= 1 && abs(enemy_y - hero_y) <= 1) {
		attack();
		return;
	}
	if (!moveable) { return; }
	Cell origin_cell = floor->getCell(enemy_x, enemy_y);
	vector<Cell> moveable_cells;
	for (int i = enemy_x - 1; i <= enemy_x + 1; ++i) {
		for (int j = enemy_y - 1; j <= enemy_y + 1; ++j) {
			if (i == enemy_x && j == enemy_y) { continue; }
			Cell neighbour_cell = floor->getCell(i, j);
			if (neighbour_cell.isOccupied()) { return; }
			moveable_cells.emplace_back(neighbour_cell);
		}
	}
	int count_moveable = moveable_cells.size();
	int random_num = helper::random(count_moveable);
	Cell next_cell = moveable_cells.at(random_num);
	ConcreteCell *ccell = origin_cell.GetConcreteCell();
	next_cell.SetConcreteCell(ccell);
	origin_cell.deleteConcrete();
}

void Enemy::attack() {
	int miss_random = helper::random(2);
	if (miss_random == 0) {
		return;
	}
	double damage = ceil((100 / (100 + hero->getDef())) * getAtk());
	//int damage = helper::ceiling((100 / (100 + hero->getDef())) * getAtk());

	if (hero->carryBarrier()) {
		damage = ceil(damage / 2);
		//damage = helper::ceiling(damage / 2);
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

