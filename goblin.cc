#include "goblin.h"

using namespace std;

Goblin::Goblin() {
	type = 'N';
	hasCompass = false;
	moveable = true;
}

double Goblin::dropGold() const{
	return 1;
}

/*void Goblin::setHostile(bool isHostile) {
	Goblin::isHostile = isHostile;
}

bool Goblin::getHostile() const {
	return this->isHostile;
}*/

Goblin::~Goblin() {}
