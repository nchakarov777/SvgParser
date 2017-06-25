#include<string>

#include "Controller.h"

#ifndef __Console__
#define __Console__
class Console {
private:
    Controller controller;
    std::string operation, suboperation;
    int shapeIndex;

public:
    Console();

    static const std::string OPEN;
    static const std::string PRINT;
    static const std::string ERASE;
    static const std::string CREATE;
    static const std::string EXIT;
    static const std::string SAVE;

    void createShape();
    void printMenu();
    void processMenuSelection(std::string operation);
    void startApplication();
};

#endif // __Console__

