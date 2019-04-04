#ifndef _VAMPIRE_H
#define _VAMPIRE_H

#include "enemy.h"

class Vampire final: public Enemy {
    bool isHostile;
    public:
        Vampire();
        double dropGold() const override;
        void setHostile(bool isHostile) override ;
        bool getHostile() const override ;
        char GetType() const override;
        ~Vampire();
};

#endif //_VAMPIRE_H
