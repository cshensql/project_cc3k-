#include "human.h"
#include <math.h>

using namespace std;

Human::Human() {
    hp = 140;
    atk = 20;
    def = 20;
    maxHp = 140;
    race = "Human";
    goldNum = 0;
    hasBarrier = false;
}

Human::~Human() {}
