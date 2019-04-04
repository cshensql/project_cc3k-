#ifndef _GOBLIN_H
#define _GOBLIN_H

#include "enemy.h"

class Goblin final: public Enemy {
    bool isHostile;
    public:
        Goblin();
        double dropGold() const override;
        void setHostile(bool isHostile) override ;
        bool getHostile() const override ;
    char GetType() const override;
        ~Goblin();
};

#endif //_GOBLIN_H
