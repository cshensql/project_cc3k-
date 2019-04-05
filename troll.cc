#include "troll.h"
using namespace std;

Troll::Troll() {
	type = 'T';
	hasCompass = false;
	moveable = true;
//	Troll::isHostile = true;
}

double Troll::dropGold() const {
	return 1;
}

/*void Troll::setHostile(bool ifHostile) {
	Troll::isHostile = ifHostile;
}

bool Troll::getHostile() const {
	return Troll::isHostile;
} */

char Troll::GetType() const {
	return 'T';
}

Troll::~Troll() {}
