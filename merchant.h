#ifndef _MERCHANT_H
#define _MERCHANT_H

#include "enemy.h"

class Merchant final: public Enemy {
        static bool isHostile;
    public:
        Merchant();
        double dropGold() const override;
        void setHostile(bool isHostile) override ;
        bool getHostile() const override ;
        ~Merchant();
};

#endif //_MERCHANT_H
