

#ifndef __Controller__
#define __Controller__


#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include "../shapes/Shape.h"

using namespace std;

class Controller
{

private:
    vector<Shape*> shapes;
public:
    Controller();

    vector<Shape*> openAndReadSvgFile(string fileName);
    Shape* generateShapeFromString(string svgObject);
    Shape* generateShapeFromConsole();

    void createShape();
    void eraseShape(int shapeIndex);
    void printShapes();

};

#endif // __Controller__
