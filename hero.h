#ifndef _HERO_H
#define _HERO_H

#include <string>
#include "character.h"
#include "enemy.h"

class Hero: public Character {
    protected:
        std::string race; //first letter is uppercase
        int maxHp;
        int goldNum;
        bool hasBarrier;
        Floor *floor = nullptr;
    public:
        std::string getRace();
        int getGold();
        void usePotion(Potion *potion);
        void move(std::string direction);
        void pickPotion(std::string direction);
        void pickGold(std::string direction);
        void pickCompass(std::string direction);
        void attackDir(std::string direction);
        virtual void attack(Enemy *enemy) = 0;
        virtual void attackedByEnemy(Enemy *enemy) = 0;
        virtual ~Hero() = 0;
};

#endif //_HERO_H
