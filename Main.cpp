#include <iostream>
#include <fstream>
#include <string>
#include "Command04.h"
#include "Command05.h"
#include "DataGenerator.h"
#include "Resource.h"
#include <chrono>

using namespace std;
int main(int argc, char** argv)
{
    // ofstream of ("data3.txt");

    // int *a = new int[10000];
    
    // GenerateData(a, 10000, 3);

    // of << 10000 << endl;

    // for(int i = 0; i < 10000; i++){
    //     of << a[i] << " ";
    // }

    // of.close();
    //Command04(argv[2],argv[3],argv[4]);
    Command05(argv[2], argv[3], argv[4], argv[5]);
    return 0;
}