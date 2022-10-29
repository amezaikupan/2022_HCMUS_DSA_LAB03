#include <chrono>
#include "..\Helper\Ultility.h"

using namespace std;

/// <summary>
///	Combine array in sorted order, only focus on running 
/// </summary>
void Merge_Time(int* &a, int left, int right, int mid)
{
	int leftArrSize = mid - left + 1;
	int rightArrSize = right - mid;

	// Create 2 smaller temporary arrays from main array
	int* leftArray = new int[leftArrSize];
	int* rightArray = new int[rightArrSize];

	// Assign value from main array to temporary arrays
	for (int i = 0; i < leftArrSize; i++)
		leftArray[i] = a[left + i];
	for (int i = 0; i < rightArrSize; i++)
		rightArray[i] = a[i + mid + 1];

	// Current considering index of right, left and main array
	int leftIndex = 0;
	int rightIndex = 0;
	int mainIndex = left;

	while (leftIndex < leftArrSize && rightIndex < rightArrSize)
	{
		if (leftArray[leftIndex] < rightArray[rightIndex])
		{
			a[mainIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else
		{
			a[mainIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		mainIndex++;
	}

	// Assign the remaining elements to the main array
	while (leftIndex < leftArrSize)		// If left array still has unconsidered element
	{
		a[mainIndex] = leftArray[leftIndex];
		leftIndex++;
		mainIndex++;
	}

	while (rightIndex < rightArrSize)	// If right array still has unconsidered element
	{
		a[mainIndex] = rightArray[rightIndex];
		rightIndex++;
		mainIndex++;
	}

	// Delete the temporary arrays
	delete[] leftArray;
	delete[] rightArray;
}


/// <summary>
///	Combine array in sorted order, focus on counting comparisons 
/// </summary>
void Merge_Comp(int* &a, int left, int right, int mid, long long& comp)
{
	int leftArrSize = mid - left + 1;
	int rightArrSize = right - mid;

	// Create 2 smaller temporary arrays from main array
	int* leftArray = new int[leftArrSize];
	int* rightArray = new int[rightArrSize];

	// Assign value from main array to temporary arrays
	for (int i = 0; ++comp && i < leftArrSize; i++)
		leftArray[i] = a[left + i];
	for (int i = 0; ++comp && i < rightArrSize; i++)
		rightArray[i] = a[i + mid + 1];

	// Current considering index of right, left and main array
	int leftIndex = 0;
	int rightIndex = 0;
	int mainIndex = left;

	while (++comp && leftIndex < leftArrSize && ++comp && rightIndex < rightArrSize)
	{
		if (++comp && leftArray[leftIndex] < rightArray[rightIndex])
		{
			a[mainIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else
		{
			a[mainIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		mainIndex++;
	}

	// Assign the remaining elements to the main array
	while (++comp && leftIndex < leftArrSize)		// If left array still has unconsidered element
	{
		a[mainIndex] = leftArray[leftIndex];
		leftIndex++;
		mainIndex++;
	}

	while (++comp && rightIndex < rightArrSize)	// If right array still has unconsidered element
	{
		a[mainIndex] = rightArray[rightIndex];
		rightIndex++;
		mainIndex++;
	}

	// Delete the temporary arrays
	delete[] leftArray;
	delete[] rightArray;
}

/// <summary>
/// Merge sort recursion loop, only focus on running 
/// </summary>
void MergeSortRecursion_Time(int* &a, int begin, int end)
{
	if (end <= begin)
		return;
	int mid = (begin + end) / 2;
	MergeSortRecursion_Time(a, begin, mid);
	MergeSortRecursion_Time(a, mid + 1, end);
	Merge_Time(a, begin, end, mid);
}


/// <summary>
/// Merge sort recursion loop, focus on counting comparisions
/// </summary>
void MergeSortRecursion_Comp(int* &a, int begin, int end, long long& comp)
{
	if (++comp && end <= begin)
		return;
	int mid = (begin + end) / 2;
	MergeSortRecursion_Comp(a, begin, mid, comp);
	MergeSortRecursion_Comp(a, mid + 1, end, comp);
	Merge_Comp(a, begin, end, mid, comp);
}

/// <summary>
/// Sort an array by dividing it into 2 equal halves and then combining them into a sorted order
/// </summary>
/// <param name="a"> : The array need to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="time"> : The amount of time it takes after running the function (output value) </param>
void MergeSortTime(int* &a, int n, double& time)
{
	auto start = chrono::high_resolution_clock::now();   // Start measure time 

	MergeSortRecursion_Time(a, 0, n - 1);		// Start sorting in recursion

	auto stop = chrono::high_resolution_clock::now();    // Stop measure time
	time = (chrono::duration_cast<chrono::microseconds>(stop - start).count()) / 1000.0;
}

/// <summary>
/// Sort an array by dividing it into 2 equal halves and then combining them into a sorted order
/// </summary>
/// <param name="a"> : The array need to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="comp"> : The number of comparisions it needs after running the function (output value) </param>
void MergeSortComp(int* &a, int n, long long& comp)
{
	comp = 0;
	MergeSortRecursion_Comp(a, 0, n - 1, comp);
}
