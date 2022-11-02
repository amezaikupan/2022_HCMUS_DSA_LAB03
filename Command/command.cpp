#include <iostream>
#include <string.h>

#include "command01.h"
#include "command02.h"
#include "command03.h"
#include "Command04.h"
#include "Command05.h"

using namespace std;

void ChooseCommand(int argc, char** argv){
    if(argc == 5){
        if(strcmp(argv[1], "-a") == 0){
            if(atoi(argv[3]) == 0){
                cout << "ALGORITHM MODE" << endl;
                cout << "Algorithm: " << argv[2] << endl;
                cout << "Input file: " << argv[3] << endl;
                cout << "Input size: " << endl;
                cout << "--------------------------------" << endl;
                command01(argv[2], argv[3], argv[4]);
            }else{
                cout << "ALGORITHM MODE" << endl;
                cout << "Algorithm: " << argv[2] << endl;
                cout << "Input file: " << endl;
                cout << "Input size: " << argv[3] << endl;
                cout << "--------------------------------" << endl;
                command03(argv[2], argv[3], argv[4]);
            }
        }
        else if(strcmp(argv[1], "-c") == 0){
            Command04(argv[2],argv[3],argv[4]);
        }else{
            cout << "INVALID COMMAND" << endl;
        }
    }
    else if(argc == 6){
        if(strcmp(argv[1], "-a") == 0){
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << argv[2] << endl;
            cout << "Input file: " << endl;
            cout << "Input size: " << argv[3] << endl;
            cout << "--------------------------------" << endl;
            command02(argv[2], argv[3], argv[4], argv[5]);
        }
        else if(strcmp(argv[1], "-c") == 0){
            Command05(argv[2], argv[3], argv[4], argv[5]);
        }else{
            cout << "INVALID COMMAND" << endl;
        }
    }
}