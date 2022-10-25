#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <chrono>
#include  "Command04.h"
#include "DataGenerator.h"
#include "Resource.h"
//#include"Source.h"
using namespace std;

int* readData(char* input, int& n)
{
    //Read input file
    ifstream file (input);
    
    //Get data set's size
    //string line = "";
    //getline(file, line);

    //Make data set
    //n = stoi(line);
    string line;
    int* a = new int[n];

    //Read data set data
    int i = 0;
    file >> n;
    while(file >> line){
        
        a[i] = stoi(line);
        i++;
    } 
    
    return a;
}
//Command 04
void ChooseAlgorithm(char* Algorithm, int* input, int n, int &time, int &compare)
{
    if(strcmp(Algorithm,"selection-sort")==0)
    {
        //Compare
        SelectionSortCom(input,n,compare);
        //Time
        SelectionSortTime(input, n, time);
       

    }
    else if(strcmp(Algorithm, "insertion-sort")==0)
    {
        //Compare
        InsertionSortCom(input,n,compare);
        //Time
        InsertionSortTime(input, n, time);
    }
    else if(strcmp(Algorithm, "bubble-sort")==0)
    {
        //Compare
        BubbleSortCom(input, n, compare);
        //Time
        BubbleSortTime(input,n, time);
    }
    else if(strcmp(Algorithm, "heap-sort")==0)
    {
        //Compare
        HeapSortCom(input, n, compare);
        //Time
        HeapSortTime(input,n, time);
        

    }
    else if(strcmp(Algorithm, "merge-sort")==0)
    {
        
    }
    else if(strcmp(Algorithm, "quick-sort")==0)
    {
        
    }
    else if(strcmp(Algorithm, "radix-sort")==0)
    {

    }
    else
    {
        return;
    }
}
void Command04(char* Algorithm01, char* Algorithm02, char* Input)
{
    //Reading data from input
    int n;
    int *a;
    a = readData(Input, n);
    
    int time01 = 0, time02 = 0;
    int  compare01, compare02;

    ChooseAlgorithm(Algorithm01, a, n, time01, compare01);
    ChooseAlgorithm(Algorithm02, a, n, time02, compare02);

    cout << Algorithm01 << " | " << Algorithm02 << endl;
    cout << "Input file: " << Input << endl;
    cout << "Input size: " << n << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Running time: " << time01 << " | " << time02 << endl;
    cout << "Comparisions: " << compare01 << " | " << compare02 << endl;
    delete[] a;
}

