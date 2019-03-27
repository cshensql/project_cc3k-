#ifndef _HUMAN_H
#define _HUMAN_H

#include "hero.h"
#include "enemy.h"

class Human final: public Hero {
    public:
        Human();
        void attack(Enemy *enemy) override;
        void attackedByEnemy(Enemy *enemy) override;
        ~Human();
}

#endif //_HUMAN_H
