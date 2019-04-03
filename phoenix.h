#ifndef _PHOENIX_H
#define _PHOENIX_H

#include "enemy.h"
#include "hero.h"

class Phoenix final: public Enemy {
    static bool isHostile;
    public:
        Phoenix();
        int dropGold() const override;
        void setHostile(bool isHostile) override;
        bool getHostile() const override;
        ~Phoenix();
};

#endif //_PHOENIX_H
