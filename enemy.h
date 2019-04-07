#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"

class Hero;
class Floor;

class Enemy: public Character {
    protected:
        char type;
        Hero *hero = nullptr;
        bool hasCompass = false;
        bool moveable;
//      static bool isHostile;
        Floor *floor = nullptr;
    public:
        void setHero(Hero *hero);
        void setFloor(Floor *floor);
        void setCompass(bool has_compass);
	bool getCompass();
        char getType() const;
        void moveNext();
        void attack();
//      virtual void setHostile(bool isHostile) = 0;
//      virtual bool getHostile() const = 0;
        virtual double dropGold() const = 0;
        virtual ~Enemy() = 0;
};

#endif //_ENEMY_H

