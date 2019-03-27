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
        void attack(Hero *hero) override;
        void attackedByHero(Hero *hero) override;
        const int dropGold() override;
        ~Dragon();
}

#endif //_DRAGON_H
