#include<string>

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
public :
    Shape(string name);
    ~Shape();
    char* getName();
    string getStroke();
    string getFillColor();

    void setName(string name);
    void setStroke(string stroke);
    void setFillColor(string fillColor);
};

#endif // __Shape__
