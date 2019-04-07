#include "character.h"

using namespace std;

Character::~Character() {}

int Character::getHp() const {
    return this->hp;
}

int Character::getAtk() const {
    return this->atk;
}

int Character::getDef() const {
    return this->def;
}

void Character::setHp(int Hp) {
    this->hp = Hp;
}

void Character::setAtk(int Atk) {
    this->atk = Atk;
}

void Character::setDef(int Def) {
    this->def = Def;
}

bool Character::isAlive() const {
    return (this->hp > 0);
}

