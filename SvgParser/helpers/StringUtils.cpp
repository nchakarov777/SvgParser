#include "StringUtils.h"
#include<iostream>
#include<cstring>
#include<sstream>
string StringUtils::getPropertyValue(string property)
{
    string result = "";
    int position = property.find("=");
    for(int i = position+2; i<property.length(); i++ )
    {
        if(property[i]!='"')
        {
            result+=property[i];
        }
        else
        {
            break;
        }
    }
    return result;
}

int StringUtils::convertStringToInt(string integer)
{
    int result;
    istringstream ss(integer);
    ss >> result;
    return result;
}

string StringUtils::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    return ss.str();
}
