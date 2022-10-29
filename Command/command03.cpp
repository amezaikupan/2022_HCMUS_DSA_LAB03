#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "../Algorithm/SortingAlgorithm.h"
#include "../Helper/FileManipulation.h"
#include "../Helper/dataGenerator.h"
#include "../Helper/Ultility.h"

using namespace std;

void command03Comp(char* algorithm, int n){
    int *a = new int[n];

    long long comp[4] = {0, 0, 0, 0};

    string file;

    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    switch (al)
    {
    case 1:
        //Selection Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            SelectionSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 2:
        //Insertion Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            InsertionSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 3:
        //Bubble Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            BubbleSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 4:
        //Shaker Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            ShakerSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        
        break;
    case 5:
        //Shell Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            ShellSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 6:
        //Heap Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            HeapSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 7:
        //Merge Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            MergeSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 8:
        //Quick Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            QuickSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 9:
        //Counting Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            CountingSortCom(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 10:
        //Radix Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            RadixSortComp(a, n, comp[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        
        break;
    case 11:
        //Flash Sort
        break;
    default:
        //Error
        break;
    }
    
    for(int i = 0; i < 4; i++){        
        cout << "Running time (if required): " << endl;
        cout << "Comparisons (if required): "  << comp[i] << endl;
    }

    delete[] a;

}

void command03Time(char* algorithm, int n){
    int *a = new int[n];

    double time[4] = {0, 0, 0, 0};
    string file;

    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    switch (al)
    {
    case 1:
        //Selection Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            SelectionSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 2:
        //Insertion Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            InsertionSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 3:
        //Bubble Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            BubbleSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 4:
        //Shaker Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            ShakerSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        
        break;
    case 5:
        //Shell Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            ShellSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 6:
        //Heap Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            HeapSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 7:
        //Merge Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            MergeSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 8:
        //Quick Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            QuickSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 9:
        //Counting Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            CountingSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 10:
        //Radix Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            
            RadixSortTime(a, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        
        break;
    case 11:
        //Flash Sort
        break;
    default:
        //Error
        break;
    }
    
    for(int i = 0; i < 4; i++){        
        cout << "Running time (if required): " << time[i] << endl;
        cout << "Comparisons (if required): "  << endl;
    }

    delete[] a;

}

void command03Both(char* algorithm, int n){
    int *a = new int[n];
    int *b = new int[n];
    long long comp[4] = {0, 0, 0, 0};
    double time[4];
    string file;


    //Get algorithm 
    int al = getAlgorithm(algorithm);

    //Process Command
    switch (al)
    {
    case 1:
        //Selection Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            SelectionSortComp(a, n, comp[i]);
            SelectionSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 2:
        //Insertion Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            InsertionSortComp(a, n, comp[i]);
            InsertionSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 3:
        //Bubble Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            BubbleSortComp(a, n, comp[i]);
            BubbleSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 4:
        //Shaker Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            ShakerSortComp(a, n, comp[i]);
            ShakerSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
    case 5:
        //Shell Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            ShellSortComp(a, n, comp[i]);
            ShellSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 6:
        //Heap Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            HeapSortComp(a, n, comp[i]);
            HeapSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 7:
        //Merge Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            MergeSortComp(a, n, comp[i]);
            MergeSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 8:
        //Quick Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            QuickSortComp(a, n, comp[i]);
            QuickSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }

        break;
    case 9:
        //Counting Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            CountingSortCom(a, n, comp[i]);
            CountingSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        break;
        break;
    case 10:
        //Radix Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            RadixSortComp(a, n, comp[i]);
            RadixSortTime(b, n, time[i]);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
        }
        
        break;
    case 11:
        //Flash Sort
        break;
    default:
        //Error
        break;
    }
    
    for(int i = 0; i < 4; i++){        
        cout << "Running time (if required): " << time[i] << endl;
        cout << "Comparisons (if required): "  << comp[i] << endl;
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
}