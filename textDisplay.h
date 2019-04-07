#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H

#include <string>

class Floor;
class Hero;

class TextDisplay {
    Floor *floor;
    std::string action;
    int floorNumber;
    std::string heroName;
    int gold;
    int hp;
    int atk;
    int def;
public:
    TextDisplay();
    ~TextDisplay();
    void updateAction(std::string action);
    void updateHeroInfo(Hero *hero);
    void setFloor(Floor *floor);
    void render();
};

#endif //_TEXTDISPLAY_H

