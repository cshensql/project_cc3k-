#ifndef _TROLL_H
#define _TROLL_H

#include "enemy.h"
#include "hero.h"

class Troll final: public Enemy {
    public:
        Troll();
        void attack(Hero *hero) override;
        void attackedByHero(Hero *hero) override;
        const int dropGold() override;
        ~Troll();
}

#endif //_TROLL_H
