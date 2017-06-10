#include<cstring>
#include<iostream>

#include "../shapes/Shape.h"
#include "../controllers/Controller.h"

using namespace std;

//open C:\Users\nikit\Desktop\svg1.svg

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

    return 0;
}
