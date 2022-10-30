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
                command01(argv[2], argv[3], argv[4]);
            }else{
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
            command02(argv[2], argv[3], argv[4], argv[5]);
        }
        else if(strcmp(argv[1], "-c") == 0){
            Command05(argv[2], argv[3], argv[4], argv[5]);
        }else{
            cout << "INVALID COMMAND" << endl;
        }
    }else{
            cout << "INVALID PARAMETER" << endl;
    }
}