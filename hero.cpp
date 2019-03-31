#include "hero.h"
using namespace std;

class Hero: public Character {
    protected:
        std::string race; //first letter is uppercase
        int maxHp;
        int goldNum;
        bool hasBarrier;
        Floor *floor = nullptr;

string Hero::getRace() {
    return this->race;
}
        
int Hero::getGold() {
    return this->goldNum;
}
        
void Hero::usePotion(Potion *potion) {
    potion->beingDrunk();
}
        
void Hero::move(string direction) {
    int X = getX();
    int Y = getY();
    X = helper::findX(X, direction);
    Y = helper::findY(Y, direction);
    setX(X);
    setY(Y);
}
        
void Hero::pickPotion(string direction) {
    int X = getX();
    int Y = getY();
    X = Helper::findX(X, direction);
    Y = Helper::findY(Y, direction);
    // to be continue
}
        
void Hero::pickGold(string direction) {

}
        
void Hero::pickCompass(string direction) {

}
        
void Hero::attackDir(string direction) {

}
        
Hero::~Hero() {
    delete floor;
}

