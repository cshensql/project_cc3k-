#include <iostream>
#include "werewolf.h"
using namespace std;

Werewolf::Werewolf() {
    type = 'W';
    hasCompass = false;
    moveable = true;
    setHp(120);
    setAtk(30);
    setDef(5);
}

double Werewolf::dropGold() const {
    return 1;
}

/*void Werewolf::setHostile(bool isHostile) {
    Werewolf::isHostile = isHostile;
}

bool Werewolf::getHostile() const{
    return this->isHostile;
}*/

char Werewolf::GetType() const {
    return 'W';
}

Werewolf::~Werewolf() {}

