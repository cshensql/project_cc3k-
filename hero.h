#ifndef _HERO_H
#define _HERO_H

#include <string>
#include "character.h"

class Enemy;
class Potion;
class Floor;
class Cell;

class Hero: public Character {
    protected:
        std::string race; //first letter is uppercase
        int maxHp;
        double goldNum = 0;
        bool hasBarrier = false;
        bool hasCompass = false;
        Floor *floor = nullptr;
    public:
    void SetType();
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
        bool pickGold(Cell &gold_cell); // return a boolean value to check if gold is picked up by hero
        void pickCompass(std::string direction);
        void pickBarrierSuit(std::string direction);
        Enemy *attackDir(std::string direction); // return a nullptr if there is no enemy at the direction
        int attack(Enemy *enemy);
        virtual void setDefaultAtkDef() = 0;
        virtual ~Hero() = 0;
};

#endif //_HERO_H
