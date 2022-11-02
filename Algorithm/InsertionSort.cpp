#include <chrono>
#include "../Helper/Ultility.h"

using namespace std;

void InsertionSortComp(int* &a, int n, long long&  comp)
{
	 comp = 0;
	int i = 1, j, key;
	while (++ comp && i < n)
	{
		key = a[i];
		j = i - 1;
		while (++ comp && j >= 0 && ++ comp && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		i++;
	}
}

void InsertionSort(int* &a, int n)
{
	int i = 1, j, key;
	while (i < n)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		i++;
	}
}

void InsertionSortTime(int* &a, int n, double &elapsed_time)
{
	chrono::time_point<chrono::high_resolution_clock> start, end;
	start = chrono::high_resolution_clock::now();

	InsertionSort(a, n);

	end = chrono::high_resolution_clock::now();
	elapsed_time = double(chrono::duration_cast <chrono::nanoseconds> (end - start).count()) / 1e6;
}


