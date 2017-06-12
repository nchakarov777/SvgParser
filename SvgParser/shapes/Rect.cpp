#include <sstream>
#include <iostream>

#include "Rect.h"
#include "Shape.h"

#include "../helpers/StringUtils.h"
#include "../helpers/ShapeProperties.h"

using namespace std;

Rect::Rect(string svgObject):Shape(Shape::RECT)
{
    if(checkValid(svgObject))
    {
        istringstream objectStream(svgObject);
        string property;
        objectStream>>property;

        do
        {
            objectStream>>property;
            if(property.find("/>") != string::npos)
            {
                break;
            }
            setProperty(property);
        }
        while(objectStream);
    }
}

Rect::Rect():Shape(Shape::RECT)
{
    setValid(true);
}


bool Rect::checkValid(string svgObject)
{
    if(svgObject.empty())
    {
        setValid(false);
    }
    else
    {
        setValid(true);
    }
    return getValid();
}

void Rect::setProperty(string property)
{
    if(property.find(ShapeProperties::HEIGHT)!=string::npos)
    {

        string value = StringUtils::getPropertyValue(property);
        setHeight(StringUtils::convertStringToInt(value));
        return;
    }
    if(property.find(ShapeProperties::WIDTH)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setWidth(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::STROKE)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setStroke(value);
        return;
    }

    if(property.find(ShapeProperties::FILL)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setFillColor(value);
        return;
    }

    if(property.find(ShapeProperties::X)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setX(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::Y)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setY(StringUtils::convertStringToInt(value));
        return;
    }
}

void Rect::setHeight(int height)
{
    this->height = height;
}

void Rect::setWidth(int width)
{
    this->width = width;
}

void Rect::setX(int x)
{
    this->x = x;
}

void Rect::setY(int y)
{
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

Rect::~Rect()
{

}

void Rect::print(ostream& os)
{
    Shape::print(os);
    os<<getX()<<" "<<getY()<<" "<<getHeight()<<" "<<getWidth()<<" "<<getFillColor()<<endl;
}

Shape* Rect::create()
{

    Rect* rect = new Rect();
    int x, y, height, width;
    string fillColor;

    cin>>x>>y>>height>>width>>fillColor;

    rect->setX(x);
    rect->setY(y);
    rect->setHeight(height);
    rect->setWidth(width);
    rect->setFillColor(fillColor);

    return rect;
}
