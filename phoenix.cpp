#include "phoenix.h"
using namespace std;

Phoenix::Phoenix() {
	type = 'X';
	hasCompass = false;
	moveable = true;
}

int Phoenix::dropGold() const{
	return 1;
}

void Phoenix::setHostile(bool isHostile) {
	this->isHostile = isHostile;
}

bool Phoenix::getHostile() const {
	return this->isHostile;
}

Phoenix::~Phoenix() {}