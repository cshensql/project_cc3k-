#ifndef _DRAGON_H
#define _DRAGON_H

#include "enemy.h"
#include "hero.h"
#include "dragonhoard.h"
#include "barriersuit.h"

class Dragon final: public Enemy {
        DragonHoard *dragonH = nullptr;
        BarrierSuit *barrierS = nullptr;
    public:
        Dragon();
        int dropGold() const override;
        void setDragonHoard(DragonHoard *dragon_hoard);
        void setBarrierSuit(BarrierSuit *barrier_suit);
        ~Dragon();
};

#endif //_DRAGON_H
