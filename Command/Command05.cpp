#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "../Algorithm/SortingAlgorithm.h"
#include "../Helper/FileManipulation.h"
#include "../Helper/dataGenerator.h"
#include "../Helper/Ultility.h"
#include "Command04.h"

using namespace std;

void Command05 (char* Algorithm01, char* Algorithm02, char* Input, char* Order)
{
    int n = atoi(Input);
    int *a = new int[n];
    int *b;
    //a = readData(Input, n);
    double time01 = 0, time02 = 0;
    long long compare01 = 0, compare02 = 0;

    string file = "intput.txt";
    
    int o = getOrder((Order));
    
    //Check if enter invalid order
    if(o == -1){
        cout << "INVALID ORDER" << endl;
        return;
    }

    GenerateData(a, n, o);
    b = copyData(a, b, n);

    ChooseAlgorithm(Algorithm01, a, n, time01, compare01);
    ChooseAlgorithm(Algorithm02, b, n, time02, compare02);
    writeData(file, a, n);
   
    cout << "COMPARISON MODE: " << endl;
    cout << Algorithm01 << " | " << Algorithm02 << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: " << Order << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Running time: " << time01 << " | " << time02 << endl;
    cout << "Comparisions: " << compare01 << " | " << compare02 << endl;
    
    delete[] a;
    delete[] b;
}
