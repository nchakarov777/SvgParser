#include<iostream>
#include "Controller.h"
#include "Shape.h"
using namespace std;

const string OPEN = "open";

string operation, suboperation;
Controller controller = Controller();

void printMenu(){
    cout<<"For reading some svg file please type --> open filename.svg"<<endl;
}

void processOperation(string opr){
    if(opr.find(OPEN) != string::npos){
        cin>>suboperation;
        controller.openAndReadSvgFile(suboperation);
    }
}

int main()
{

    while(operation!="exit"){
        printMenu();
        cin>>operation;
        processOperation(operation);
    }

    Shape shape = Shape("ivan");
    cout<<shape.getName();

    return 0;
}
