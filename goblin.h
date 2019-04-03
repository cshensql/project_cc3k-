#ifndef _GOBLIN_H
#define _GOBLIN_H

#include "enemy.h"
#include "hero.h"

class Goblin final: public Enemy {
    static bool isHostile;
    public:
        Goblin();
        int dropGold() const override;
        void setHostile(bool isHostile) override ;
        bool getHostile() const override ;
        ~Goblin();
};

#endif //_GOBLIN_H
