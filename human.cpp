#include "human.h"
#include <math.h>

using namespace std;

Human::Human() {
    hp = 140;
    atk = 20;
    def = 20;
    maxHp = 140;
    race = "Human";
    maxHp = 140;;
    goldNum = 0;
    hasBarrier = false;
}

void Human::attack(Enemy *enemy) {
    int damage = ceil((100 / (100 + enemy->getDef())) * atk);
    if (enemy->getHp() <= damage) {
        enemy->setHp(0);
    } else {
        enemy->setHp(enemy->getHp() - damage);
    }
}

void Human::attackedByEnemy(Enemy *enemy) {
    int damage = ceil((100 / (100 + def)) * enemy->getAtk());
    if (hasBarrier) {
        damage = ceil(damage / 2);
    }
    if (hp <= damage) {
        hp = 0;
    } else {
        hp = hp - damage;
    }
}

Human::~Human() {}
