#include<iostream>
#include<string>

#include "Console.h"
#include "Controller.h"

const string Console::OPEN = "open";
const string Console::PRINT = "print";
const string Console::ERASE = "erase";
const string Console::CREATE = "create";
const string Console::SAVE = "save";
const string Console::EXIT = "exit";

Console::Console()
{
    controller = Controller();
}

void Console::printMenu()
{
    cout<<"For reading some svg file please type -->$ open filename.svg"<<endl;
    cout<<"For printing the loaded files -->$ print"<<endl;
    cout<<"For erasing loaded shape -->$ erase shapeIndex"<<endl;
    cout<<"For creating new shape -->$ create shapeData"<<endl;
    cout<<"For saving the shapes in a svg file -->$ save"<<endl;
    cout<<"For exiting the application -->$ exit"<<endl;
}

void Console::processMenuSelection(string opr)
{
    if(opr.find(Console::OPEN) != string::npos)
    {
        cin>>suboperation;
        controller.openAndReadSvgFile(suboperation);
    }

    if(opr.find(Console::PRINT) != string::npos)
    {
        controller.printShapes();
    }

    if(opr.find(Console::ERASE) != string::npos)
    {
        cin>>shapeIndex;
        controller.eraseShape(shapeIndex);
    }

    if(opr.find(Console::CREATE) != string::npos)
    {
        controller.createShape();
    }

    if(opr.find(Console::SAVE) != string::npos)
    {
        controller.saveShapes();
    }
}

void Console::startApplication()
{
    while(operation!=Console::EXIT)
    {
        printMenu();
        cin>>operation;
        processMenuSelection(operation);
    }
}
