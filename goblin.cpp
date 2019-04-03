#include "goblin.h"
using namespace std;

Goblin::Goblin() {
	type = 'N';
	hasCompass = false;
	moveable = true;
}

int Goblin::dropGold() {
	return 1;
}

Goblin::~Goblin() {}