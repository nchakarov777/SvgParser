#include <sstream>
#include <iostream>

#include "Circle.h"
#include "Shape.h"

#include "../helpers/StringUtils.h"
#include "../helpers/ShapeProperties.h"

using namespace std;

Circle::Circle(string svgObject):Shape("circle")
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

bool Circle::checkValid(string svgObject)
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

void Circle::setProperty(string property)
{
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

    if(property.find(ShapeProperties::RADIUS)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setRadius(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::CENTER_X)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setCX(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::CENTER_Y)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setCY(StringUtils::convertStringToInt(value));
        return;
    }

}

void Circle::setRadius(int radius)
{
    cout<<radius<<" ";
    this->radius = radius;
}

void Circle::setCX(int cx)
{
    cout<<cx<<" ";
    this->cx = cx;
}

void Circle::setCY(int cy)
{
    cout<<cy<<" ";
    this->cy = cy;
}

int Circle::getCX()
{
    return cx;
}

int Circle::getCY()
{
    return cy;
}

int Circle::getRadius()
{
    return radius;
}

Circle::~Circle()
{

}

void Circle::print(ostream& os)
{
    Shape::print(os);
    os<<getCX()<<" "<<getCY()<<" "<<getRadius()<<" "<<getFillColor()<<endl;
}
