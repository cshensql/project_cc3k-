#ifndef FINAL_PROJECT_BASICCELL_H
#define FINAL_PROJECT_BASICCELL_H

class BasicCell{
protected:
    int x;
    int y;
public:
    BasicCell(); // Default Ctor
    BasicCell(int x, int y);
    ~BasicCell();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};

#endif
