#include "compass.h"
#include "enemy.h"

Compass::Compass() {
    setPickable(true);
}

//void Compass::setHolder (Enemy *enemy_holder) {
//    holder = enemy_holder;
//}

char Compass::GetType() const {
    return 'C';
}

Compass::~Compass() {
}

