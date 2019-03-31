#ifndef _TREASURE_H
#define _TREASURE_H

#include <string>
#include "item.h"

class Treasure: public Item {
        int value;
        std::string type;
        bool picked;
    public:
        std::string getType () const;
        char GetType() override const;
	void setType(std::string typename);
        int getValue() const;
	void setValue(int amount);
	bool getState() const;
	void setState(bool picked);
        virtual ~Treasure() = 0;
};

#endif //_TREASURE_H 
