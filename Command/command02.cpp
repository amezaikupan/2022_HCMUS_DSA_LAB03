#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "../Algorithm/SortingAlgorithm.h"
#include "../Helper/FileManipulation.h"
#include "../Helper/dataGenerator.h"
#include "../Helper/Ultility.h"

using namespace std;

void printCommand02(char* algorithm, int n, long long comp = -1, int time = -1){
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << n << endl;
    cout << "--------------------------------" << endl;
    if(time != -1)  cout << "Running time: " << time << endl;
    if(comp != -1)  cout << "Comparisons: " << comp << endl;
}

void command02Comp(char* algorithm, int n, char* order){
    //Generate data
    int* a = new int[n];
    int o = getOrder((order));

    //Check if enter invalid order
    if(o == -1){
        cout << "INVALID ORDER" << endl;
        return;
    }

    GenerateData(a, n, o);
    writeData("input.txt", a, n);
    
    long long comp = 0, count_while = 0;

    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    switch (al)
    {
    case 1:
        //Selection Sort
        SelectionSortComp(a, n, comp);

        break;
    case 2:
        //Insertion Sort
        InsertionSortComp(a, n, comp);

        break;
    case 3:
        //Bubble Sort
        BubbleSortComp(a, n, comp);

        break;

    case 4:
        //Shaker Sort
        ShakerSortComp(a, n, comp);
        break;
    case 5:
        //Shell Sort
        ShellSortComp(a, n, comp);

        break;
    case 6:
        //Heap Sort
        HeapSortComp(a, n, comp);

        break;
    case 7:
        //Merge Sort
        MergeSortComp(a, n, comp);
        break;
    case 8:
        //Quick Sort
        QuickSortComp(a, n, comp);

        break;
    case 9:
        //Counting Sort
        CountingSortCom(a, n, comp);
        break;
    case 10:
        //Radix Sort
        RadixSortComp(a, n, comp);
        break;
    case 11:
        //Flash Sort
        FlashSortComp(a, n, comp);
        break;
    default:
        //Error
        cout << "INVALID ALGORITHM NAME" << endl;
        return;
        
    }

    writeData("output.txt", a, n);

    printCommand02(algorithm, n, comp);

    cout << "Running time (): " << endl;
    cout << "Comparisons (): " << comp << endl;

    delete[] a;
}

void command02Time(char* algorithm, int n, char* order){
    //Generate data

    //Generate data
    int* a = new int[n];
    int o = getOrder((order));
    
    //Check if enter invalid order
    if(o == -1){
        cout << "INVALID ORDER" << endl;
        return;
    }

    GenerateData(a, n, o);
    writeData("input.txt", a, n);
    
    double time = 0;

    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    switch (al)
    {
    case 1:
        //Selection Sort
        SelectionSortTime(a, n, time);

        break;
    case 2:
        //Insertion Sort
        InsertionSortTime(a, n, time);

        break;
    case 3:
        //Bubble Sort
        BubbleSortTime(a, n, time);

        break;

    case 4:
        //Shaker Sort
        ShakerSortTime(a, n, time);
        break;
    case 5:
        //Shell Sort
        ShellSortTime(a, n, time);

        break;
    case 6:
        //Heap Sort
        HeapSortTime(a, n, time);

        break;
    case 7:
        //Merge Sort
        MergeSortTime(a, n, time);

        break;
    case 8:
        //Quick Sort
        QuickSortTime(a, n, time);

        break;
    case 9:
        //Counting Sort
        CountingSortTime(a, n ,time);
        break;
    case 10:
        //Radix Sort
        RadixSortTime(a, n, time);
        break;
    case 11:
        //Flash Sort
        FlashSortTime(a, n, time);
        break;
    default:
        //Error
        cout << "INVALID ALGORITHM NAME" << endl;
        return;
        
    }
   
    writeData("output.txt", a, n);

    printCommand02(algorithm, n, -1, time);

    cout << "Running time (): " << time << endl;
    cout << "Comparisons (): "  << endl;

    delete[] a;
}

void command02Both(char* algorithm, int n, char* order){
    //Generate data

    //Generate data
    int* a = new int[n];
    int* b = new int[n];

    int o = getOrder((order));

    //Check if enter invalid order
    if(o == -1){
        cout << "INVALID ORDER" << endl;
        return;
    }

    GenerateData(a, n, o);
    b = copyData(a, b, n);
    //GenerateData(b, n, o);

    writeData("input.txt", a, n);
    
    double time = 0;
    long long comp = 0;

    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    switch (al)
    {
    case 1:
        //Selection Sort
        SelectionSortComp(a, n, comp);
        SelectionSortTime(b, n, time);

        break;
    case 2:
        //Insertion Sort
        InsertionSortComp(a, n, comp);
        InsertionSortTime(b, n, time);

        break;
    case 3:
        //Bubble Sort
        BubbleSortComp(a, n, comp);
        BubbleSortTime(b, n, time);

        break;
    case 4:
        //Shaker Sort
        ShakerSortComp(a, n, comp);
        ShakerSortTime(b, n, time);
        
        break;
    case 5:
        //Shell Sort
        ShellSortComp(a, n, comp);
        ShellSortTime(b, n, time);

        break;
    case 6:
        //Heap Sort
        HeapSortComp(a, n, comp);
        HeapSortTime(b, n, time);

        break;
    case 7:
        //Merge Sort
        MergeSortComp(a, n, comp);
        MergeSortTime(b, n, time);

        break;
    case 8:
        //Quick Sort
        QuickSortComp(a, n, comp);
        QuickSortTime(b, n, time);

        break;
    case 9:
        //Counting Sort
        CountingSortCom(a, n, comp);
        CountingSortTime(b, n, time);

        break;
    case 10:
        //Radix Sort
        RadixSortComp(a, n, comp);
        RadixSortTime(b, n, time);
        
        break;
    case 11:
        //Flash Sort
        FlashSortComp(a, n, comp);
        FlashSortTime(b, n, time);
        break;
    default:
        //Error
        cout << "INVALID ALGORITHM NAME" << endl;
        return;
        
    }
    
    writeData("output.txt", a, n);

    printCommand02(algorithm, n, comp, time);

    delete[] a;
    delete[] b;

}

void command02(char* algorithm, char* size, char* order, char* para){
    
    int n = atoi(size);
    
    if(strcmp(para, "-comp") == 0){
        command02Comp(algorithm, n, order);        
    }
    else if(strcmp(para, "-time") == 0){
        command02Time(algorithm, n, order);
    }
    else if(strcmp(para, "-both") == 0){
        command02Both(algorithm, n, order);
    }
    else{
        cout << "INVALID PARAMETER" << endl;
    }
}