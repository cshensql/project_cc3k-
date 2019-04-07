#ifndef _WEREWOLF_H
#define _WEREWOLF_H

#include "enemy.h"

class Werewolf final: public Enemy {
//    static bool isHostile;
    public:
        Werewolf();
        double dropGold() const override;
//        void setHostile(bool isHostile) override ;
//        bool getHostile() const override ;
        char GetType() const override;
        ~Werewolf();
};

#endif //_WEREWOLF_H

