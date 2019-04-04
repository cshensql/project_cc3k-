#ifndef _DRAGON_H
#define _DRAGON_H

#include "enemy.h"

class DragonHoard;
class BarrierSuit;

class Dragon final: public Enemy {
        DragonHoard *dragonH = nullptr;
        BarrierSuit *barrierS = nullptr;
        static bool isHostile;
    public:
        Dragon();
        double dropGold() const override;
        void setDragonHoard(DragonHoard *dragon_hoard);
        void setBarrierSuit(BarrierSuit *barrier_suit);
        DragonHoard *getDragonHoard() const;
        BarrierSuit *getBarrierSuit() const;
        void setHostile(bool isHostile) override;
        bool getHostile() const override;
        ~Dragon();
};

#endif //_DRAGON_H
