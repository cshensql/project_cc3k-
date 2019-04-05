#include "phoenix.h"
using namespace std;

Phoenix::Phoenix() {
	type = 'X';
	hasCompass = false;
	moveable = true;
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

Phoenix::~Phoenix() {}
