#include "werewolf.h"
using namespace std;

Werewolf::Werewolf() {
	type = 'W';
	hasCompass = false;
	moveable = true;
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

Werewolf::~Werewolf() {}
