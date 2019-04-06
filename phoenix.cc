#include <iostream>
#include "phoenix.h"
using namespace std;

Phoenix::Phoenix() {
	type = 'X';
	hasCompass = false;
	moveable = true;
	setHp(50);
	setAtk(35);
	setDef(20);
}

double Phoenix::dropGold() const{
	return 1;
}

/*void Phoenix::setHostile(bool isHostile) {
	Phoenix::isHostile = isHostile;
}

bool Phoenix::getHostile() const {
	return this->isHostile;
}*/

char Phoenix::GetType() const {
	return 'X';
}

Phoenix::~Phoenix() {}
