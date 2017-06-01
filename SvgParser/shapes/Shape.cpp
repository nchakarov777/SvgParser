#include "Shape.h"
#include<iostream>
#include<cstring>
using namespace std;


Shape::Shape(string name)
{
    int nameL = name.length()+1;
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

void Shape::setFillColor(string color){
    this->fillColor=color;
}

void Shape::setStroke(string stroke){
    this->stroke = stroke;
}

/**Used dynamic char array only to prove my teacher, that I can properly use them.*/
void Shape::setName(string name){
    int nameL = name.length()+1;
    this->name = new char[nameL];
    for(int i = 0; i < nameL; i++)
    {
        this->name[i] = name[i];
    }
}
