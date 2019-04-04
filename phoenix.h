#ifndef _PHOENIX_H
#define _PHOENIX_H

#include "enemy.h"

class Phoenix final: public Enemy {
    static bool isHostile;
    public:
        Phoenix();
        double dropGold() const override;
        void setHostile(bool isHostile) override;
        bool getHostile() const override;
        ~Phoenix();
};

#endif //_PHOENIX_H
