#ifndef _GOBLIN_H
#define _GOBLIN_H

#include "enemy.h"
#include "hero.h"

class Goblin final: public Enemy {
    public:
        Goblin();
        void attack(Hero *hero) override;
        void attackedByHero(Hero *hero) override;
        const int dropGold() override;
        ~Goblin();
}

#endif //_GOBLIN_H
