#ifndef _VAMPIRE_H
#define _VAMPIRE_H

#include "enemy.h"
#include "hero.h"

class Vampire final: public Enemy {
    static bool isHostile;
    public:
        Vampire();
        double dropGold() const override;
        void setHostile(bool isHostile) override ;
        bool getHostile() const override ;
        ~Vampire();
};

#endif //_VAMPIRE_H
