#include "Rect.h"
#include "../helpers/StringUtils.h"
#include "../helpers/ShapeProperties.h"
#include <sstream>
#include <iostream>
#include "./Shape.h"
using namespace std;

Rect::Rect(string svgObject):Shape("rect")
{
    cout<<svgObject<<endl;
    istringstream objectStream(svgObject);
    string property;
    objectStream>>property;

    do
    {
        objectStream>>property;
        cout<<property<<endl;
        if(property.find("/>") != string::npos){
            break;
        }
        setProperty(property);
    }
    while(objectStream);
}

void Rect::setProperty(string property) throw(string)
{
    if(property.find(ShapeProperties::HEIGHT))
    {
        string value = StringUtils::getPropertyValue(property);
        setHeight(StringUtils::convertStringToInt(value));
        return;
    }
    if(property.find(ShapeProperties::WIDTH))
    {
        string value = StringUtils::getPropertyValue(property);
        setWidth(StringUtils::convertStringToInt(value));
        return;
    }
    if(property.find(ShapeProperties::X))
    {
        string value = StringUtils::getPropertyValue(property);
        setX(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::Y))
    {
        string value = StringUtils::getPropertyValue(property);
        setY(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::STROKE))
    {
        string value = StringUtils::getPropertyValue(property);
        setStroke(value);
        return;
    }

    if(property.find(ShapeProperties::FILL))
    {
        string value = StringUtils::getPropertyValue(property);
        setFillColor(value);
        return;
    }

    throw("Unsupported property");
}

void Rect::setHeight(int height)
{
    cout<<height<<" ";
    this->height = height;
}

void Rect::setWidth(int width)
{
    cout<<width<<" ";
    this->width = width;
}

void Rect::setX(int x)
{
    cout<<x<<" ";
    this->x = x;
}

void Rect::setY(int y)
{
    cout<<y<<" ";
    this->y = y;
}

int Rect::getX()
{
    return x;
}

int Rect::getY()
{
    return y;
}

int Rect::getWidth()
{
    return width;
}

int Rect::getHeight()
{
    return height;
}

Rect::~Rect(){

}
