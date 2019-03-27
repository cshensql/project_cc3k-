#ifndef _TREASURE_H
#define _TREASURE_H

#include <string>
#include "item.h"

class Treasure: public Item {
        const int value;
        std::string type;
        bool picked;
    public:
        const std::string getType();
        const int getValue();
        ~Treasure();
}

#endif //_TREASURE_H 
