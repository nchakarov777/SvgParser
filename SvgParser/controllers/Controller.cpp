#include "Controller.h"
#include "../shapes/Rect.h"
#include<fstream>
#include<vector>

using namespace std;

static const char* const values[] = {"rect", "cyrcle", "line"};

Controller::Controller()
{

}

vector<Shape> Controller::openAndReadSvgFile(string fileName)
{
    ifstream svg;
    //As mentioned here https://stackoverflow.com/questions/10966446/passing-a-string-to-file-open
    svg.open(fileName.c_str());
    if (svg.is_open())
    {
        cout<<"inside"<<endl;
        for(string line; getline(svg, line);){
            Shape shape = craeteShapeObject(line);
            if(strlen(shape.getName())>=1){
                shapes.push_back(shape);
            }
        }
    }
    svg.close();

    return shapes;
}

Shape Controller::craeteShapeObject(string svgObject){
    if(svgObject.find(values[0])!= string::npos){
        return Rect(svgObject);
    }
    return Shape("");
}


