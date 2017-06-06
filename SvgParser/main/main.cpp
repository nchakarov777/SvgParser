#include<iostream>
#include<cstring>
#include "../controllers/Controller.h"
#include "../shapes/Shape.h"
using namespace std;

static const string OPEN = "open";
static const string PRINT = "print";

string operation, suboperation;
Controller controller = Controller();

void printMenu(){
    cout<<"For reading some svg file please type -->$ open filename.svg"<<endl;
    cout<<"For printing the loaded files -->$ print"<<endl;
}

void processOperation(string opr){
    if(opr.find(OPEN) != string::npos){
        cin>>suboperation;
        controller.openAndReadSvgFile(suboperation);
    }

    if(opr.find(PRINT) != string::npos){
        controller.printShapes();
    }
}

int main()
{

    while(operation!="exit"){
        printMenu();
        cin>>operation;
        processOperation(operation);
    }

    Shape shape("name");
    cout<<shape.getName();


    return 0;
}
