#include <chrono>
#include "..\Helper\Ultility.h"

using namespace std;
/// <summary>
/// Sort an array by repeatedly swapping the adjacent elements if they are in the wrong order 
/// </summary>
/// <param name="a"> : The array need to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="time"> : The amount of time it takes after running the function (output value) </param>
void BubbleSortTime(int* &a, int n, double& time)
{
	auto start = chrono::high_resolution_clock::now();   // Start measure time 
	bool finishedSwap = false;

	// Note: the section below is an improved version of bubble sort 

	//while (!finishedSwap)		// Sort until all elements in array don't need to swap
	//{
	//	finishedSwap = true;
	//	for (int i = 0; i < n - 1; i++)
	//		if (a[i] > a[i + 1])
	//		{
	//			swap(a[i], a[i + 1]);
	//			finishedSwap = false;
	//		}
	//}

	// Not improved version
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);

	auto end = chrono::high_resolution_clock::now();
	time = double(chrono::duration_cast <chrono::nanoseconds> (end - start).count()) / 1e6;
}

/// <summary>
/// Sort an array by repeatedly swapping the adjacent elements if they are in the wrong order 
/// </summary>
/// <param name="a"> : The array need to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="comp"> : The number of comparisions it needs after running the function (output value) </param>
void BubbleSortComp(int* &a, int n, long long& comp)
{
	bool finishedSwap = false;
	comp = 0;

	for (int i = 0; ++comp && i < n - 1; i++)
		for (int j = 0; ++comp && j < n - 1; j++)
			if (++comp && a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}