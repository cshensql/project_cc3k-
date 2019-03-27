#ifndef _VAMPIRE_H
#define _VAMPIRE_H

#include "enemy.h"
#include "hero.h"

class Vampire final: public Enemy {
    public:
        Vampire();
        void attack(Hero *hero) override;
        void attackedByHero(Hero *hero) override;
        const int dropGold() override;
        ~Vampire();
}

#endif //_VAMPIRE_H
