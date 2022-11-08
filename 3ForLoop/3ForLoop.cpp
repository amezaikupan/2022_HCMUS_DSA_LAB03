#include <iostream>
#include <string.h>
#include "../Command/command.h"
#include "../Algorithm/SortingAlgorithm.h"
#include "../Helper/FileManipulation.h"
#include "../Helper/dataGenerator.h"
#include "../Helper/Ultility.h"
#include "../Command/command04.h"
void Running()
{
    int a[6] = {10000, 30000, 50000, 100000, 300000, 500000};
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            int* arr = new int[a[j]];
            GenerateData(arr, a[j], i);
    
            for(int k = 0; k< 11; k++)
            {
                int* copyarr = copyData(arr, copyarr, a[j]);
                long long comp = 0; double time = 0;

                string s= getAlgorithmName(k + 1);

                char* algorithm = new char[s.size() + 1];
                strcpy(algorithm, s.c_str());

                ChooseAlgorithm ( algorithm, copyarr, a[j], time, comp);

                cout << "Data Order: " << getOrderName(i) <<endl;
                cout << "Data Size: " << a[j] << endl;
                cout << "Algorithm: " << s << endl;
                cout << "Comparision: " << comp << endl;
                cout << "Running time : " << time << endl;
                cout << "__________________________________" << endl;
                delete[] algorithm;
                delete[] copyarr;
            }
            delete [] arr;
        }
    }
}
