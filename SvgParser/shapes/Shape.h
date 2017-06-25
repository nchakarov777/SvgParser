#include<string>
#include<iostream>

using namespace std;

#ifndef __Shape__
#define __Shape__
/**
    Base class which any svg shape class should inherit.
*/
class Shape
{
protected:

    char* name;
    string stroke;
    string fillColor;
    bool valid;
public :
    static const string RECT;
    static const string CIRCLE;
    static const string LINE;

    Shape(string name);
    virtual ~Shape();

    char* getName();
    string getStroke();
    string getFillColor();
    bool getValid();

    void setValid(bool valid);
    void setName(string name);
    void setStroke(string stroke);
    void setFillColor(string fillColor);

    virtual void print(ostream &os) = 0;
    virtual string getShapeAsSvg() = 0;
};

ostream& operator << (ostream& os, Shape* shape);


#endif // __Shape__
