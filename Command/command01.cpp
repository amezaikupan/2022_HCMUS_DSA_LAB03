#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "../Algorithm/SortingAlgorithm.h"
#include "../Helper/FileManipulation.h"
#include "../Helper/Ultility.h"

using namespace std;

void printCommand01(char* algorithm, char* input, int n, long long comp = -1, int time = -1){
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input file: " << input << endl;
    cout << "Input size: " << n << endl;
    cout << "--------------------------------" << endl;
    
    if(time != -1)  cout << "Running time: " << time << endl;
    if(comp != -1)  cout << "Comparisons: " << comp << endl;
}

//Proccess comparisons count -comp
void command01Comp(char* algorithm, char* input){
    //Read data
    int n = 0;
    int* a = readData(input, n);

    if(a == NULL){
        cout << "INVALID FILE NAME" << endl;
        return;
    }

    //Comparisons
    long long comp = 0;

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
        break;
    }

    writeData("output.txt", a, n);
    printCommand01(algorithm, input, n, comp);

    delete[] a;
}

//Process running time -time
void command01Time(char* algorithm, char* input){
    
    //Read data
    int n = 0;
    int* a = readData(input, n);

    if(a == NULL){
        cout << "INVALID FILE NAME" << endl;
        return;
    }

    double time;

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
        CountingSortTime(a, n, time);
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

    printCommand01(algorithm, input, n, -1, time);

    delete[] a;
}

//Process comparisons count and running time -both
void command01Both(char* algorithm, char* input){

     //Read data
    int n = 0;
    int* a = readData(input, n);
    
    if(a == NULL){
        cout << "INVALID FILE NAME" << endl;
        return;
    }
    
    int* b = readData(input, n);

    double time = 0;
    long long comp = 0;

    
    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    switch (al)
    {
    case 1:
        //Selection Sort
        SelectionSortTime(a, n, time);
        SelectionSortComp(b, n, comp);
        break;
    case 2:
        //Insertion Sort
        InsertionSortTime(a, n, time);
        InsertionSortComp(b, n, comp);
        break;
    case 3:
        //Bubble Sort
        BubbleSortTime(a, n, time);
        BubbleSortComp(b, n, comp);
        break;

    case 4:
        //Shaker Sort
        ShakerSortTime(a,n,time);
        ShakerSortComp(b,n,comp);

        break;
    case 5:
        //Shell Sort
        ShellSortComp(a, n, comp);
        ShellSortTime(b, n, time);
        
        break;
    case 6:
        //Heap Sort
        HeapSortTime(a, n, time);
        HeapSortComp(b, n, comp);

        break;
    case 7:
        //Merge Sort
        MergeSortTime(a, n, time);
        MergeSortComp(b, n, comp);

        break;
    case 8:
        //Quick Sort
        QuickSortTime(a, n, time);
        QuickSortComp(b, n, comp);

        break;
    case 9:
        //Counting Sort
        CountingSortTime(a, n, time);
        CountingSortCom(b, n, comp);
        break;
    case 10:
        //Radix Sort
        RadixSortTime(a, n, time);
        RadixSortComp(b, n, comp);

        break;
    case 11:
        //Flash Sort
        FlashSortTime(a, n, time);
        FlashSortComp(b, n, comp);
        break;
    default:
        //Error
        cout << "INVALID ALGORITHM NAME" << endl;
        return;
    }
    writeData("output.txt", a, n);

    printCommand01(algorithm, input, n, comp, time);

    delete[] a;
    delete[] b;

}


void command01(char* algorithm, char* input, char* para){
    if(strcmp(para, "-comp") == 0){
        command01Comp(algorithm, input);        
    }
    else if(strcmp(para, "-time") == 0){
        command01Time(algorithm, input);
    }
    else if(strcmp(para, "-both") == 0){
        command01Both(algorithm, input);
    }
    else{
        cout << "INVALID PARAMETER" << endl;
    }
}