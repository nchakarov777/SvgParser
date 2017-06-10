#include <sstream>
#include <iostream>

#include "Line.h"
#include "Shape.h"

#include "../helpers/StringUtils.h"
#include "../helpers/ShapeProperties.h"

using namespace std;

Line::Line(string svgObject):Shape("line")
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

bool Line::checkValid(string svgObject)
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

void Line::setProperty(string property)
{
    if(property.find(ShapeProperties::STROKE)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setStroke(value);
        return;
    }

    if(property.find(ShapeProperties::FIRST_X)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setFirstX(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::FIRST_Y)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setFirstY(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::SECOND_X)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setSecondX(StringUtils::convertStringToInt(value));
        return;
    }

    if(property.find(ShapeProperties::SECOND_Y)!=string::npos)
    {
        string value = StringUtils::getPropertyValue(property);
        setSecondY(StringUtils::convertStringToInt(value));
        return;
    }

}

void Line::setFirstX(int x1)
{
    this->x1 = x1;
}

void Line::setFirstY(int y1)
{
    this->y1 = y1;
}

void Line::setSecondX(int x2)
{
    this->x2 = x2;
}

void Line::setSecondY(int y2)
{
    this->y2 = y2;
}

int Line::getFirstX()
{
    return x1;
}

int Line::getSecondX()
{
    return x2;
}

int Line::getFirstY()
{
    return y1;
}

int Line::getSecondY()
{
    return y2;
}

Line::~Line()
{

}

void Line::print(ostream& os)
{
    Shape::print(os);
    os<<getFirstX()<<" "<<getFirstY()<<" "<<getSecondX()<<" "<<getSecondY()<<endl;
}
