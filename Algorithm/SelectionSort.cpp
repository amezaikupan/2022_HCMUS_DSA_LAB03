#include "..\Helper\Ultility.h"
#include <chrono>
using namespace std;

/// <summary>
/// Sort an array by repeatedly finding the minimum element (considering ascending order) of that array and putting it at the beginning 
/// </summary>
/// <param name="a"> : The array to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="time"> : The amount of time it takes after running the function (output value) </param>
void SelectionSortTime(int* &a, int n, double& time)
{
    auto start = chrono::high_resolution_clock::now();   // Start measure time 

    for (int i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;      // Index of the smallest number from a[i] to a[n - 1]
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[smallestIndex])
                smallestIndex = j;
        
        if (smallestIndex != i)     // In case a[i] is the smallest number then we don't need to swap
            swap(a[i], a[smallestIndex]);
    }

    auto stop = chrono::high_resolution_clock::now();    // Stop measure time
    time = double(chrono::duration_cast<chrono::nanoseconds>(stop - start).count()) / 1e6;
}

/// <summary>
/// Sort an array by repeatedly finding the minimum element (considering ascending order) of that array and putting it at the beginning 
/// </summary>
/// <param name="a"> : The array to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="comp"> : The number of comparisions it needs after running the function (output value) </param>
void SelectionSortComp(int* &a, int n, long long& comp)
{
    comp = 0;

    for (int i = 0; ++comp && i < n - 1; i++)
    {
        int smallestIndex = i;      // Index of the smallest number from a[i] to a[n - 1]
        for (int j = i + 1; ++comp && j < n; j++)
            if (++comp && a[j] < a[smallestIndex])
                smallestIndex = j;

        if (++comp && smallestIndex != i)     // In case a[i] is the smallest number then we don't need to swap
            swap(a[i], a[smallestIndex]);
    }
}
