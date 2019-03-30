#ifndef _PHOENIX_H
#define _PHOENIX_H

#include "enemy.h"
#include "hero.h"

class Phoenix final: public Enemy {
    public:
        Phoenix();
        void attack(Hero *hero) override;
        void attackedByHero(Hero *hero) override;
        const int dropGold() override;
        ~Phoenix();
};

#endif //_PHOENIX_H
