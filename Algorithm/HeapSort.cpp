#include <chrono>
#include "../Helper/Ultility.h"

using namespace std;

// Count comparisons
void HeapRebuildComp(int pos, int* &a, int n, long long & comp)
{
	int k = pos;
	bool isHeap = false;
	int j;
	while (++ comp && isHeap != true && 2 * k + 1 < n)
	{
		j = 2 * k + 1;
		if (++ comp && j < n - 1)
		{
			if (++ comp && a[j] < a[j + 1])
			{
				j = j + 1;
			}
		}
		if (++ comp && a[k] >= a[j])
		{
			isHeap = true;
		}
		else
		{
			swap(a[k], a[j]);
			k = j;
		}
	}
}

void HeapConstructComp(int* &a, int n, long long & comp)
{
	int index = (n - 1) / 2;
	while (++ comp && index >= 0)
	{
		HeapRebuildComp(index, a, n,  comp);
		index = index - 1;
	}
}

void HeapSortComp(int* &a, int n, long long & comp)
{
	int r;
	HeapConstructComp(a, n,  comp);
	r = n - 1;
	while (++ comp && r > 0)
	{
		swap(a[0], a[r]);
		HeapRebuildComp(0, a, r,  comp);
		r = r - 1;
	}
}

//Execution time:
void HeapRebuildTime(int pos, int* &a, int n)
{
	int k = pos;
	bool isHeap = false;
	int j;
	while (isHeap != true && 2 * k + 1 < n)
	{
		j = 2 * k + 1;
		if (j < n - 1)
		{
			if (a[j] < a[j + 1])
			{
				j = j + 1;
			}
		}
		if (a[k] >= a[j])
		{
			isHeap = true;
		}
		else
		{
			swap(a[k], a[j]);
			k = j;
		}
	}
}

void HeapConstructTime(int* &a, int n)
{
	int index = (n - 1) / 2;
	while (index >= 0)
	{
		HeapRebuildTime(index, a, n);
		index = index - 1;
	}
}

void HeapSort(int* &a, int n)
{
	int r;
	HeapConstructTime(a, n);
	r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		HeapRebuildTime(0, a, r);
		r = r - 1;
	}
}

void HeapSortTime(int* &a, int n, double &elapsed_time)
{
	chrono::time_point<chrono::high_resolution_clock> start, end;
	start = chrono::high_resolution_clock::now();

	HeapSort(a, n);

	end = chrono::high_resolution_clock::now();
	elapsed_time = double(chrono::duration_cast <chrono::nanoseconds> (end - start).count()) / 1e6;
}


