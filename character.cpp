#include "character.h"

using namespace std;

Character::~Character() {
    delete cell;
}

int Cell::getHp() const {
    return this->hp;
}

int Cell::getMaxHp() {
    return this->maxHp;
}

int Cell::getAtk() const {
    return this->atk;
}

int Cell::getDef() const {
    return this->def;
}

void Cell::setHp(int Hp) {
    this->hp = Hp;
}
    
void Cell::setAtk(int Atk) {
    this->atk = Atk;
}
    
void Cell::setDef(int Def) {
    this->def = Def;
}
    
bool Cell::isAlive() const {
    return (hp <= 0);
}
