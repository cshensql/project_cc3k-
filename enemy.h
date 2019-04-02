#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include "floor.h"
#include "hero.h"

class Hero;
class Floor;

class Enemy: public Character {
    protected:
        char type;
        Hero *hero = nullptr;
        bool hasCompass = false;
        bool moveable;
        Floor *floor = nullptr;
    public:
        Enemy *createEnemy(char enemy_type, bool has_compass);
        void setHero(Hero *hero);
        void setFloor(Floor *floor);
        char getType();
        void moveNext();
        void attack(Hero *hero);
		virtual const int dropGold() = 0;
        virtual ~Enemy() = 0;
};

#endif //_ENEMY_H
