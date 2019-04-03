#include "phoenix.h"
using namespace std;

Phoenix::Phoenix() {
	type = 'X';
	hasCompass = false;
	moveable = true;
}

int Phoenix::dropGold() {
	return 1;
}

Phoenix::~Phoenix() {}