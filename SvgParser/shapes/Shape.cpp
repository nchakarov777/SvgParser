#include<cstring>
#include<iostream>

#include "Shape.h"

using namespace std;

const string Shape::RECT = "rect";
const string Shape::CIRCLE = "circle";
const string Shape::LINE = "line";

Shape::Shape(string name)
{
    int nameL = name.length()+1;
    this->name = new char[nameL];
    for(int i = 0; i < nameL; i++)
    {
        this->name[i] = name[i];
    }
}

const char* Shape::getName()
{
    return name;
}

Shape::~Shape()
{
    delete[] name;
}

void Shape::setFillColor(string color)
{
    this->fillColor=color;
}

void Shape::setStroke(string stroke)
{
    this->stroke = stroke;
}

string Shape::getFillColor()
{
    return fillColor;
}

/**Used dynamic char array only to prove my teacher, that I can properly use them.*/
void Shape::setName(string name)
{
    int nameL = name.length()+1;
    this->name = new char[nameL];
    for(int i = 0; i < nameL; i++)
    {
        this->name[i] = name[i];
    }
}

void Shape::setValid(bool valid)
{
    this->valid = valid;
}

bool Shape::getValid()
{
    return valid;
}

void Shape::print(ostream &os)
{
    os<<getName()<<" ";
}

ostream& operator << (ostream& os,  Shape* shape)
{
    shape->print(os);
    return os;
}

