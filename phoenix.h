#ifndef _PHOENIX_H
#define _PHOENIX_H

#include "enemy.h"

class Phoenix final: public Enemy {
    bool isHostile;
    public:
        Phoenix();
        double dropGold() const override;
        void setHostile(bool isHostile) override;
        bool getHostile() const override;
    char GetType() const override;
        ~Phoenix();
};

#endif //_PHOENIX_H
