#ifndef _HERO_H
#define _HERO_H

#include <string>
#include "character.h"
#include "enemy.h"

class Hero: public Character {
    protected:
        std::string race; //first letter is uppercase
        int maxHp;
        double goldNum = 0;
        bool hasBarrier = false;
        bool hasCompass = false;
        Floor *floor = nullptr;
    public:
        char GetType() const override;
        std::string getRace() const;
        double getGold() const;
        bool carryCompass() const;
        bool carryBarrier() const;
        void setRace(std::string race_type);
        void setMaxHp(int max_hp);
        void setGoldNum(double gold_num);
        void addBarrier();
        void setFloor(Floor *f);
        void move(std::string direction);
        Potion *pickPotion(std::string direction);
        void pickGold(std::string direction);
        void pickCompass(std::string direction);
        void pickBarrierSuit(string direction);
        Enemy *attackDir(std::string direction);
        double attack(Enemy *enemy);
        virtual ~Hero() = 0;
};

#endif //_HERO_H
