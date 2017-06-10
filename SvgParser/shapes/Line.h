#include<iostream>

#include "Shape.h"

#ifndef __Line__
#define __Line__
class Line: public Shape {
private:
    int x1, y1, x2, y2;

public:
    Line(string svgLine);
    ~Line();

    bool checkValid(string svgLine);

    int getFirstX();
    int getFirstY();
    int getSecondX();
    int getSecondY();


    void setProperty(string property);
    void setSecondX(int x2);
    void setSecondY(int y2);
    void setFirstX(int x1);
    void setFirstY(int y1);

    virtual void print(ostream& os);
};

#endif // __Line__

