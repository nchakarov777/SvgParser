#include "Shape.h"
#include<iostream>
#include<cstring>
using namespace std;

Shape::Shape(char* name)
{
    int nameL = strlen(name)+1;
    this->name = new char[nameL];
    for(int i = 0; i < nameL; i++)
    {
        this->name[i] = name[i];
    }
}

char* Shape::getName(){
    return name;
}

Shape::~Shape(){
    delete[] name;
}



