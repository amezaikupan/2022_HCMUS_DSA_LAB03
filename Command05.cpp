#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "DataGenerator.h"
#include "Resource.h"
#include "Command05.h"
#include "Command04.h"
using namespace std;

void WriteFile(int* a, int n)
{
    ofstream file;
    file.open("input.txt");
    file << n;
    for(int i = 0; i < n; i++)
    {
        file << a[i] << " ";
    }
    file.close();

}
void Command05 (char* Algorithm01, char* Algorithm02, char* Input, char* Order)
{
    int n = stoi(Input);
    int *a = new int[n];
    
    //a = readData(Input, n);
    int time01 = 0, time02 = 0;
    int compare01, compare02;
    if (strcmp(Order, "-rand")==0)
    {
        GenerateData(a,n,0);
        ChooseAlgorithm(Algorithm01, a,n, time01, compare01);
        ChooseAlgorithm(Algorithm02, a,n, time02, compare02);
        WriteFile(a, n);
    }
    else if (strcmp(Order, "-nsorted")==0)
    {
        GenerateData(a,n,1);
        ChooseAlgorithm(Algorithm01, a, n, time01, compare01);
        ChooseAlgorithm(Algorithm02, a, n, time02, compare02);
        WriteFile(a, n);
    }
    else if (strcmp(Order, "-sorted")==0)
    {
        GenerateData(a,n,2);
        ChooseAlgorithm(Algorithm01, a, n, time01, compare01);
        ChooseAlgorithm(Algorithm02, a, n, time02, compare02);
        WriteFile(a, n);
    }
    else if (strcmp(Order,"-rev")==0)
    {
        GenerateData(a,n,3);
        ChooseAlgorithm(Algorithm01, a, n, time01, compare01);
        ChooseAlgorithm(Algorithm02, a, n, time02, compare02);
        WriteFile(a, n);
    }
    else
    {
        return;
    }
    cout << Algorithm01 << " | " << Algorithm02 << endl;
    cout << "Input size" << n << endl;
    cout << "Input order" << Order << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Running time: " << time01 << " | " << time02 << endl;
    cout << "Comparisions: " << compare01 << " | " << compare02 << endl;
    delete[] a;
}
