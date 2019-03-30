#ifndef _MERCHANT_H
#define _MERCHANT_H

#include "enemy.h"
#include "hero.h"

class Merchant final: public Enemy {
        static bool isHostile;
    public:
        Merchant();
        void attack(Hero *hero) override;
        void attackedByHero(Hero *hero) override;
        const int dropGold() override;
        ~Merchant();
};

#endif //_MERCHANT_H
