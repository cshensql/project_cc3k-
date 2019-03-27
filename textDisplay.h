#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H

#include "floor.h"

class TextDisplay {
    Floor *floor;
    string action;
    int floorNumber;
public:
    TextDisplay();
    ~TextDisplay();
    void updateAction(string action);
    void setFloor(Floor *floor);
    void render();
};

#endif //_TEXTDISPLAY_H