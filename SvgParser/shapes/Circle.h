#include "Shape.h"

#include<iostream>

#ifndef __Circle__
#define __Circle__
class Circle: public Shape {
private:
    int cx, cy, radius;
public:
    Circle(string svgCircle);
    Circle();
    ~Circle();

    bool checkValid(string svgCircle);

    int getCX();
    int getCY();
    int getRadius();

    void setProperty(string property);
    void setRadius(int radius);
    void setCX(int cx);
    void setCY(int cy);

    static Shape* create();
    virtual void print(ostream& os);
};

#endif // __Circle__

