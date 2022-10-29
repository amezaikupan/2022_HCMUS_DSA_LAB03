#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <chrono>
#include "../Helper/dataGenerator.h"
#include "../Algorithm/SortingAlgorithm.h"
#include "../Helper/FileManipulation.h"
#include "../Helper/Ultility.h"

//#include"Source.h"
using namespace std;

//Command 04
void ChooseAlgorithm(char* algorithm, int* a, int n, double &time, long long &comp)
{
    time = 0;
    comp = 0;

    //In case a is changed during sorting
    //int* b = new int[n];
    int* c = new int[n];
    c = copyData(a, c, n);

    //Copy a to b and c

    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Commands
    switch (al)
    {
    case 1:
        //Selection Sort
        SelectionSortTime(a, n, time);
        SelectionSortComp(c, n, comp);
        break;
    case 2:
        //Insertion Sort
        InsertionSortTime(a, n, time);
        InsertionSortComp(c, n, comp);
        break;
    case 3:
        //Bubble Sort
        BubbleSortTime(a, n, time);
        BubbleSortComp(c, n, comp);
        break;

    case 4:
        //Shaker Sort
        ShakerSortTime(a, n,time);
        ShakerSortComp(c, n, comp);
       
        break;
    case 5:
        //Shell Sort
        ShellSortComp(a, n, comp);
        ShellSortTime(c, n, time);
        
        break;
    case 6:
        //Heap Sort
        HeapSortTime(a, n, time);
        HeapSortComp(c, n, comp);

        break;
    case 7:
        //Merge Sort
        MergeSortTime(a, n, time);
        MergeSortComp(c, n, comp);

        break;
    case 8:
        //Quick Sort
        QuickSortTime(a, n, time);
        QuickSortComp(c, n, comp);

        break;
    case 9:
        //Counting Sort
        CountingSortTime(a, n, time);
        CountingSortCom(c, n, comp);
        
        break;
    case 10:
        //Radix Sort
        RadixSortTime(a, n, time);
        RadixSortComp(c, n, comp);

        break;
    case 11:
        //Flash Sort
        break;
    default:
        //Error
        break;
    }
}

void Command04(char* Algorithm01, char* Algorithm02, char* Input)
{
    //Reading data from input
    int n;
    int *a;
    int *b;
    a = readData(Input, n);
    //b = a;
    b = copyData(a, b, n);
    
    double time01 = 0, time02 = 0;
    long long compare01 = 0, compare02 = 0;

    ChooseAlgorithm(Algorithm01, a, n, time01, compare01);
    ChooseAlgorithm(Algorithm02, b, n, time02, compare02);

    cout <<"COMPARISON MODE" << endl;
    cout << Algorithm01 << " | " << Algorithm02 << endl;
    cout << "Input file: " << Input << endl;
    cout << "Input size: " << n << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Running time: " << time01 << " | " << time02 << endl;
    cout << "Comparisions: " << compare01 << " | " << compare02 << endl;

    delete[] a;
    delete[] b;
}

