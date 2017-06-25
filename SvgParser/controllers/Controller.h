

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

    vector<Shape*> openAndReadSvgFile(string fileName);
    Shape* generateShapeFromString(string svgObject);
    Shape* generateShapeFromConsole();

    void createShape();
    void eraseShape(int shapeIndex);
    void printShapes();
    void saveShapes();

};

#endif // __Controller__
