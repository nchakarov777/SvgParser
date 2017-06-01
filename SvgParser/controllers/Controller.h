

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
    vector<Shape> shapes;
public:
    Controller();
    vector<Shape> openAndReadSvgFile(string fileName);
    Shape craeteShapeObject(string svgObject);

};

#endif // __Controller__
