#ifndef _MERCHANT_H
#define _MERCHANT_H

#include "enemy.h"
#include "hero.h"

class Merchant final: public Enemy {
        static bool isHostile;
    public:
        Merchant();
        const int dropGold() override;
        ~Merchant();
};

#endif //_MERCHANT_H
