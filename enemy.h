#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include "floor.h"
#include "hero.h"

class Enemy: public Character {
    protected:
        char type;
        Hero *hero = nullptr;
        bool hasCompass;
        bool moveable;
        Floor *floor = nullptr;
    public:
        Enemy *createEnemy(char enemy_type);
        void setHero(Hero *hero);
        void setFloor(Floor *floor);
        char getType();
        void moveNext();
        virtual const int dropGold() = 0;
        virtual void attack(Hero *hero) = 0;
        virtual void attackedByHero(Hero *hero) = 0;
        virtual ~Enemy() = 0;
}

#endif //_ENEMY_H
