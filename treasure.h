#ifndef _TREASURE_H
#define _TREASURE_H

#include <string>
#include "item.h"

class Treasure: public Item {
        double value;
        std::string type;
        bool picked;
        bool pickable;
    public:
        Treasure(std::string type);
        std::string getType () const;
        char GetType() const override;
        void setType(std::string type);
        double getValue() const;
        void setValue(double amount);
        bool getState() const;
        void setState(bool picked);
        bool isPickable() const;
        void setPickable(bool pickable);
        virtual ~Treasure() = 0;
};

#endif //_TREASURE_H 
