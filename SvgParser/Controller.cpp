#include "Controller.h"
#include<fstream>

using namespace std;

Controller::Controller()
{

}

void Controller::openAndReadSvgFile(string fileName)
{
    ifstream svg;
    //Used c_str because of https://stackoverflow.com/questions/10966446/passing-a-string-to-file-open
    svg.open(fileName.c_str());
    if (svg.is_open())
    {
        cout<<"inside"<<endl;
        for(string line; getline(svg, line);){
            cout<<line<<endl;
        }
    }
    svg.close();
}
