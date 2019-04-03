#ifndef _TROLL_H
#define _TROLL_H

#include "enemy.h"
#include "hero.h"

class Troll final: public Enemy {
    static bool isHostile;
    public:
        Troll();
        double dropGold() const override;
        void setHostile(bool isHostile) override ;
        bool getHostile() const override ;
        ~Troll();
};

#endif //_TROLL_H
