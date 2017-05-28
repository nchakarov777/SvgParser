#ifndef __Shape__
#define __Shape__

class Shape
{
private:
    char* name;
public :
    Shape(char* name);
    ~Shape();
    char* getName();

};

#endif // __Shape__
