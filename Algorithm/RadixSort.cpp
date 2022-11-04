#include "..\Helper\Ultility.h"
#include <chrono>
using namespace std;


/// <summary>
/// Find the maximum number of digits in a number of an array
/// </summary>
int MaxDigit(int* &a, int n)
{
	// Find the max number in the array
	int maxNum = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > maxNum)
			maxNum = a[i];

	// Count the number of digits of that number
	int count = 0;
	while (maxNum != 0)
	{
		count++;
		maxNum /= 10;
	}

	return count;
}

/// <summary>
/// Sort an array by sorting digit by digit from least significant digit to most significant digit
/// </summary>
/// <param name="a"> : The array need to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="time"> : The amount of time it takes after running the function (output value) </param>
void RadixSortTime(int* &a, int n, double& time)
{
	auto start = chrono::high_resolution_clock::now();   // Start measure time 

	int d = MaxDigit(a, n);
	int* temp = new int[n];
	int exp = 1;
	// Note: the below part will be explained in the report
	while (d != 0)
	{
		int count[10] = { 0 };
		for (int i = 0; i < n; i++)
			count[(a[i] / exp) % 10]++;

		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (int i = n - 1; i >= 0; i--)
		{
			temp[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}

		for (int i = 0; i < n; i++)
			a[i] = temp[i];

		exp *= 10;
		d--;
	}

	delete[] temp;

	auto stop = chrono::high_resolution_clock::now();    // Stop measure time
	time = double(chrono::duration_cast<chrono::nanoseconds>(stop - start).count()) / 1e6;
}

/// <summary>
/// Sort an array by sorting digit by digit from least significant digit to most significant digit
/// </summary>
/// <param name="a"> : The array need to be sorted </param>
/// <param name="n"> : The size of the array </param>
/// <param name="comp"> : The number of comparisions it needs after running the function (output value) </param>
void RadixSortComp(int* &a, int n, long long& comp)
{
	comp = 0;

	int d = MaxDigit(a, n);
	int* temp = new int[n];
	int exp = 1;
	// Note: the below part will be explained in the report
	while (++comp && d != 0)
	{
		int count[10] = { 0 };

		for (int i = 0; ++comp && i < n; i++)
			count[(a[i] / exp) % 10]++;

		for (int i = 1; ++comp && i < 10; i++)
			count[i] += count[i - 1];

		for (int i = n - 1; ++comp && i >= 0; i--)
		{
			temp[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}

		for (int i = 0; ++comp && i < n; i++)
			a[i] = temp[i];

		exp *= 10;
		d--;
	}

	delete[] temp;
}