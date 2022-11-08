#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "../Algorithm/SortingAlgorithm.h"
#include "../Helper/FileManipulation.h"
#include "../Helper/dataGenerator.h"
#include "../Helper/Ultility.h"

using namespace std;

void printCommand03(char* algorithm, int n){
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << n << endl;
    cout <<endl;
}

void command03Comp(char* algorithm, int n){
    int *a = new int[n];

    long long comp[4] = {0, 0, 0, 0};

    string file;

    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    
    printCommand03(algorithm, n);
    cout << endl;
    for(int i = 0; i < 4; i++)
    {
        GenerateData(a,n,i);
        
        switch (i)
        {
        case 0:
            writeData("input_1.txt", a, n);
            
            break;
        case 1:
            writeData("input_3.txt", a, n);
            
            break;
        case 2:
            writeData("input_4.txt", a, n);
            
        case 3:
            writeData("input_2.txt", a, n);
            
            break;
        }
        int al = getAlgorithm(algorithm);
        switch (al)
        {
        case 1:
            //Selection Sort
            SelectionSortComp(a, n, comp[i]);
            break;
        case 2:
            //Insertion Sort
            InsertionSortComp(a, n, comp[i]);
            break;
        case 3:
            //Bubble Sort
            
            BubbleSortComp(a, n, comp[i]);

            break;
        case 4:
            //Shaker Sort
            ShakerSortComp(a, n, comp[i]);
            
            
            break;
        case 5:
            //Shell Sort
           ShellSortComp(a, n, comp[i]);

            break;
        case 6:
            //Heap Sort
            HeapSortComp(a, n, comp[i]);
            
            break;
        case 7:
            //Merge Sort
            MergeSortComp(a, n, comp[i]);

            break;
        case 8:
            //Quick Sort
            QuickSortComp(a, n, comp[i]);

            break;
        case 9:
            //Counting Sort
            CountingSortCom(a, n, comp[i]);
            break;
        case 10:
            //Radix Sort
            RadixSortComp(a, n, comp[i]);
            
            break;
        case 11:
            //Flash Sort
            FlashSortComp(a, n, comp[i]);
            break;
        default:
            //Error
            cout << "INVALID ALGORITHM NAME" << endl;
            return;
            
        }
        cout << "Input order: " << getOrderName(i) << endl;
        cout << "-------------------------------------" << endl;
        cout << "Comparisons: "  << comp[i] << endl;
        cout << endl;
    }
   

    delete[] a;

}

void command03Time(char* algorithm, int n){
    int *a = new int[n];

    double time[4] = {0, 0, 0, 0};
    string file;

    printCommand03(algorithm, n);  
    cout << endl;
    for(int i = 0; i < 4; i++)
    {
        GenerateData(a,n,i);
        switch (i)
        {
        case 0:
            writeData("input_1.txt", a, n);
            
            break;
        case 1:
            writeData("input_3.txt", a, n);
            
            break;
        case 2:
            writeData("input_4.txt", a, n);
            
        case 3:
            writeData("input_2.txt", a, n);
            
            break;
        }
         int al = getAlgorithm(algorithm);

    //Process Command
        switch (al)
        {
        case 1:
            //Selection Sort
            SelectionSortTime(a, n, time[i]);
            break;
        case 2:
            //Insertion Sort
            InsertionSortTime(a, n, time[i]);
            break;
        case 3:
            //Bubble Sort
            
            BubbleSortTime(a, n, time[i]);


            break;
        case 4:
            //Shaker Sort
            ShakerSortTime(a, n, time[i]);
            
            
            break;
        case 5:
            //Shell Sort
           ShellSortTime(a, n, time[i]);

            break;
        case 6:
            //Heap Sort
            HeapSortTime(a, n, time[i]);
            
            break;
        case 7:
            //Merge Sort
            MergeSortTime(a, n, time[i]);

            break;
        case 8:
            //Quick Sort
            QuickSortTime(a, n, time[i]);

            break;
        case 9:
            //Counting Sort
            CountingSortTime(a, n, time[i]);
            break;
        case 10:
            //Radix Sort
            RadixSortTime(a, n, time[i]);
            
            break;
        case 11:
            //Flash Sort
            FlashSortTime(a, n, time[i]);
            break;
        default:
            //Error
            cout << "INVALID ALGORITHM NAME" << endl;
            return;
            
        }
        cout << "Input order: " << getOrderName(i) << endl;
        cout << "-------------------------------------" << endl;
        cout << "Running time: " << time[i] << endl;
        cout << endl;
    }
    


    delete[] a;

}

void command03Both(char* algorithm, int n){
    int *a = new int[n];
    int *b = new int[n];
    long long comp[4] = {0, 0, 0, 0};
    double time[4] = {0, 0, 0, 0};
    string file;

    printCommand03(algorithm, n);
    cout << endl;

    for(int i = 0; i < 4; i++)
    {
        GenerateData(a,n,i);
        b = copyData(a, b, n);
        switch (i)
        {
        case 0:
            writeData("input_1.txt", a, n);
    
            break;
        case 1:
            writeData("input_3.txt", a, n);
            
            break;
        case 2:
            writeData("input_4.txt", a, n);
           
        case 3:
            writeData("input_2.txt", a, n);
            
            break;
        }
        int al = getAlgorithm(algorithm);

        switch (al)
        {
        case 1:
            //Selection Sort
            SelectionSortTime(a, n, time[i]);
            SelectionSortComp(b, n, comp[i]);
            break;
        case 2:
            //Insertion Sort
            InsertionSortTime(a, n, time[i]);
            InsertionSortComp(b, n, comp[i]);
            break;
        case 3:
            //Bubble Sort
            
            BubbleSortTime(a, n, time[i]);
            BubbleSortComp(b, n, comp[i]);

            break;
        case 4:
            //Shaker Sort
            ShakerSortTime(a, n, time[i]);
            ShakerSortComp(b, n, comp[i]);
            
            break;
        case 5:
            //Shell Sort
            ShellSortTime(a, n, time[i]);
            ShellSortComp(b, n, comp[i]);
            break;
        case 6:
            //Heap Sort
            HeapSortTime(a, n, time[i]);
            HeapSortComp(b, n, comp[i]);
            break;
        case 7:
            //Merge Sort
            MergeSortTime(a, n, time[i]);
            MergeSortComp(b, n, comp[i]);
            break;
        case 8:
            //Quick Sort
            QuickSortTime(a, n, time[i]);
            QuickSortComp(b, n, comp[i]);

            break;
        case 9:
            //Counting Sort
            CountingSortTime(a, n, time[i]);
            CountingSortCom(b, n, comp[i]);
            break;
        case 10:
            //Radix Sort
            RadixSortTime(a, n, time[i]);
            RadixSortComp(b, n, comp[i]);
            break;
        case 11:
            //Flash Sort
            FlashSortTime(a, n, time[i]);
            FlashSortComp(b, n, comp[i]);
            break;
        default:
            //Error
            cout << "INVALID ALGORITHM NAME" << endl;
            return;
        }
        cout << "Input order: " << getOrderName(i) << endl;
        cout << "-------------------------------------" << endl;
        cout << "Running time: " << time[i] << endl;
        cout << "Comparisons: " << comp[i] << endl;
        cout << endl;
    }
    
    
    delete[] a;
    delete[] b;

}

void command03(char* algorithm, char* size, char* para){
    int n = atoi(size);
    if(strcmp(para, "-time") == 0){
        command03Time(algorithm, n);
    }
    else if(strcmp(para, "-comp") == 0){
        command03Comp(algorithm, n);
    }
    else if(strcmp(para, "-both") == 0){
        command03Both(algorithm, n);
    }
    else{
        cout << "INVALID PARAMETER" << endl;
    }
}