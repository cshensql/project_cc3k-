#include <iostream>
#include "goblin.h"

using namespace std;

Goblin::Goblin() {
	type = 'N';
	hasCompass = false;
	moveable = true;
	setHp(70);
	setAtk(5);
	setDef(10);
}

double Goblin::dropGold() const{
	return 1;
}

char Goblin::GetType() const {
	return 'N';
}

/*void Goblin::setHostile(bool isHostile) {
	Goblin::isHostile = isHostile;
}

bool Goblin::getHostile() const {
	return this->isHostile;
}*/

Goblin::~Goblin() {}
