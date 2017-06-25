#include<vector>
#include<fstream>
#include<iostream>

#include "SvgFile.h"
#include "Controller.h"

#include "../shapes/Line.h"
#include "../shapes/Rect.h"
#include "../shapes/Circle.h"

using namespace std;

static const char* const values[] = {"rect", "circle", "line"};

vector<Shape*> Controller::openAndReadSvgFile(string fileName)
{
    ifstream svgFile;
    //As mentioned here https://stackoverflow.com/questions/10966446/passing-a-string-to-file-open
    svgFile.open(fileName.c_str());
    if (svgFile.is_open())
    {
        for(string line; getline(svgFile, line);)
        {
            Shape* shape = generateShapeFromString(line);
            if(shape->getValid())
            {
                shapes.push_back(shape);
                cout<<"Successfully read "<<shape->getName()<<endl;
            }
        }

        svgFile.close();
    }else{
        cout<<"Sorry a problem occurred while trying to open the file, either the path is wrong, or it does not exist."<<endl;
    }

    return shapes;
}

Shape* Controller::generateShapeFromString(string svgObject)
{
    if(svgObject.find(values[0])!= string::npos)
    {
        Rect* rect = new Rect(svgObject);
        return rect;
    }

    if(svgObject.find(values[1])!= string::npos)
    {
        Circle* circle = new Circle(svgObject);
        return circle;
    }

    if(svgObject.find(values[2])!= string::npos)
    {
        Line* line = new Line(svgObject);
        return line;
    }

    return new Rect("");
}

void Controller::printShapes()
{
    if(shapes.size())
    {
        for(int i = 0; i<shapes.size(); i++)
        {
            cout<<shapes[i];
        }
    }
    else
    {
        cout<<"No shapes found."<<endl;
    }
}

void Controller::eraseShape(int index)
{
    if(!shapes.empty() && shapes.size() >= index)
    {
        shapes.erase(shapes.begin() + index-1);
        cout<<"Successfully erase shape on "<<index<<endl;
    }
    else
    {
        cout<<"There isn't a shape on that index ;/"<<endl;
    }
}

void Controller::createShape()
{

    Shape* shape = generateShapeFromConsole();
    if(shape->getValid())
    {
        shapes.push_back(shape);
        cout<<"Successfully read "<<shape->getName()<<endl;
    }
}

Shape* Controller::generateShapeFromConsole()
{
    string shape;
    cin>>shape;


    if(shape.find(Shape::RECT) != string::npos){
        return Rect::create();
    }

    if(shape.find(Shape::CIRCLE) != string::npos){
        return Circle::create();
    }

    if(shape.find(Shape::LINE) != string::npos){
        return Line::create();
    }

    cout<<"Sorry we don't support "<<shape<<endl;
    return new Rect("");
}

void Controller::saveShapes(){
    fstream svgFile;

    //creates the file if not existing, and remove the content
    svgFile.open("figures.svg", fstream::out | fstream::trunc);

    if(svgFile.is_open()){
        svgFile<<SvgFile::SVG_HEADER;

        for(int i = 0; i<shapes.size(); i++){
            svgFile<<shapes[i]->getShapeAsSvg()<<endl;
        }

        svgFile<<SvgFile::SVG_FOOTER;

        svgFile.close();
        cout<<"Successfully saved the shapes in svg format."<<endl;
    }else{
        cout<<"Sorry a problem occurred while trying to save the shapes."<<endl;
    }
}
