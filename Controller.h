#ifndef __Controller__
#define __Controller__

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Controller
{

private:

public:
    Controller();
    void openAndReadSvgFile(string fileName);

};

#endif // __Controller__
