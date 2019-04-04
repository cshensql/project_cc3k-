#ifndef _TROLL_H
#define _TROLL_H

#include "enemy.h"

class Troll final: public Enemy {
    bool isHostile;
    public:
        Troll();
        double dropGold() const override;
        void setHostile(bool isHostile) override ;
        bool getHostile() const override ;
    char GetType() const override;
        ~Troll();
};

#endif //_TROLL_H
