#include <iostream>
#include "textDisplay.h"
using namespace std;

TextDisplay::TextDisplay() {}

TextDisplay::~TextDisplay() {
    delete floor;
}

void TextDisplay::updateAction(string action) {
    this->action = action;
}

void TextDisplay::updateHeroInfo(Hero *hero) {
    heroName = hero->getRace();
    gold = hero->getGold();
    hp = hero->getHp();
    atk = hero->getAtk();
    def = hero->getDef();
}

void TextDisplay::setFloor(Floor *floor) {
    this->floor = floor;
}

//print out the map
void TextDisplay::render() {
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 79; j++) {
            cout << this->floor->getCell(j,i).getCellType();
        }
        cout << endl;
    }
    cout << "Race: " << heroName << " " << "Gold: " << gold << "                                       " << "Floor " << floor->getCurrentFloor() << endl;
    cout << "HP: " << hp << endl;
    cout << "ATK: " << atk << endl;
    cout << "DEF: " << def << endl;
    cout << "Action: " << action << endl;
}
