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
    cout << "--------------------------------" << endl;
}

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
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            SelectionSortComp(a, n, comp[i]);          
        }

        break;
    case 2:
        //Insertion Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            InsertionSortComp(a, n, comp[i]);
        }
        break;
    case 3:
        //Bubble Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            BubbleSortComp(a, n, comp[i]);            
        }
        break;
    case 4:
        //Shaker Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            ShakerSortComp(a, n, comp[i]);            
        }
        
        break;
    case 5:
        //Shell Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            ShellSortComp(a, n, comp[i]);            
        }

        break;
    case 6:
        //Heap Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            HeapSortComp(a, n, comp[i]);
        }

        break;
    case 7:
        //Merge Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            MergeSortComp(a, n, comp[i]);

            
        }

        break;
    case 8:
        //Quick Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            QuickSortComp(a, n, comp[i]);

        }

        break;
    case 9:
        //Counting Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            CountingSortCom(a, n, comp[i]);
        }
        break;
    case 10:
        //Radix Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            RadixSortComp(a, n, comp[i]);
        }
        
        break;
    case 11:
        //Flash Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            FlashSortComp(a, n, comp[i]);
        }
        break;
    default:
        //Error
        cout << "INVALID ALGORITHM NAME" << endl;
        return;
        
    }
    
    printCommand03(algorithm, n);
    for(int i = 0; i < 4; i++){        
        cout << endl;
        cout << "Input Order: " << getOrderName(i) << endl;
        cout << "-------------------------------------" << endl;
        cout << "Comparisons: "  << comp[i] << endl;
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
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            SelectionSortTime(a, n, time[i]);
        }

        break;
    case 2:
        //Insertion Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            InsertionSortTime(a, n, time[i]);
        }
        break;
    case 3:
        //Bubble Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            BubbleSortTime(a, n, time[i]);

        }
        break;
    case 4:
        //Shaker Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            ShakerSortTime(a, n, time[i]);
        }
        
        break;
    case 5:
        //Shell Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            ShellSortTime(a, n, time[i]);

        }

        break;
    case 6:
        //Heap Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);  
            HeapSortTime(a, n, time[i]);
        }

        break;
    case 7:
        //Merge Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            MergeSortTime(a, n, time[i]);
        }

        break;
    case 8:
        //Quick Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            QuickSortTime(a, n, time[i]);
        }

        break;
    case 9:
        //Counting Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            CountingSortTime(a, n, time[i]);
        }
        break;
    case 10:
        //Radix Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            RadixSortTime(a, n, time[i]);
        }
        
        break;
    case 11:
        //Flash Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);
            FlashSortTime(a, n, time[i]);
        }
        break;
    default:
        //Error
        cout << "INVALID ALGORITHM NAME" << endl;
        return;
        
    }

    printCommand03(algorithm, n);
    for(int i = 0; i < 4; i++){        
        cout << endl;
        cout << "Input Order: " << getOrderName(i) << endl;
        cout << "-------------------------------------" << endl;
        cout << "Running time: " << time[i] << endl;
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
            b = copyData(a, b, n);\
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            SelectionSortComp(a, n, comp[i]);
            SelectionSortTime(b, n, time[i]);
        }

        break;
    case 2:
        //Insertion Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            InsertionSortComp(a, n, comp[i]);
            InsertionSortTime(b, n, time[i]);
        }
        break;
    case 3:
        //Bubble Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            BubbleSortComp(a, n, comp[i]);
            BubbleSortTime(b, n, time[i]);
        }
        break;
    case 4:
        //Shaker Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            ShakerSortComp(a, n, comp[i]);
            ShakerSortTime(b, n, time[i]);
        }
        break;
    case 5:
        //Shell Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            ShellSortComp(a, n, comp[i]);
            ShellSortTime(b, n, time[i]);
        }

        break;
    case 6:
        //Heap Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            HeapSortComp(a, n, comp[i]);
            HeapSortTime(b, n, time[i]);
        }

        break;
    case 7:
        //Merge Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            MergeSortComp(a, n, comp[i]);
            MergeSortTime(b, n, time[i]);
        }

        break;
    case 8:
        //Quick Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);

            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            QuickSortComp(a, n, comp[i]);
            QuickSortTime(b, n, time[i]);
        }

        break;
    case 9:
        //Counting Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            CountingSortCom(a, n, comp[i]);
            CountingSortTime(b, n, time[i]);
        }
        break;
        break;
    case 10:
        //Radix Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            RadixSortComp(a, n, comp[i]);
            RadixSortTime(b, n, time[i]);
        }
        
        break;
    case 11:
        //Flash Sort
        for(int i = 0; i < 4; i++){
            GenerateData(a, n, i);
            b = copyData(a, b, n);
            
            file = "input_" + to_string(i) + ".txt";
            writeData(file, a, n);

            FlashSortComp(a, n, comp[i]);
            FlashSortTime(b, n, time[i]);
        }
        break;
    default:
        //Error
        cout << "INVALID ALGORITHM NAME" << endl;
        return;
    }
    
    printCommand03(algorithm, n);
    
    for(int i = 0; i < 4; i++){     
        cout << endl;
        cout << "Input Order: " << getOrderName(i) << endl;
        cout << "-------------------------------------" << endl;
        cout << "Running time: " << time[i] << endl;
        cout << "Comparisons: "  << comp[i] << endl;
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