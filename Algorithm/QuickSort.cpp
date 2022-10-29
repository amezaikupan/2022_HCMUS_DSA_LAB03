#include <chrono>
#include "..\Helper\Ultility.h"

using namespace std;

// Count comparisons
int PartitionComp(int* &a, int first, int last, long long &count_cmp)
{
	int middle = (first + last) / 2;
	int pivot = a[middle];
	int i = first;
	int j = last;

	while (++count_cmp && i <= j)
	{
		if (++count_cmp && a[i] <= pivot)
		{
			i++;
		}
		else if (++count_cmp && a[j] >= pivot)
		{
			j--;
		}
		else
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (++count_cmp && middle < j)
	{
		swap(a[j], a[middle]);
		middle = j;
	}

	else if (++count_cmp && middle > i)
	{
		swap(a[middle], a[i]);
		middle = i;
	}

	return middle;
}

void QuickSort_Comp(int* &a, int first, int last, long long &count_cmp)
{
	if (++count_cmp && first < last)
	{
		int pivotIndex = PartitionComp(a, first, last, count_cmp);
		QuickSort_Comp(a, first, pivotIndex - 1, count_cmp);
		QuickSort_Comp(a, pivotIndex + 1, last, count_cmp);
	}
}

void QuickSortComp(int* &a, int n, long long &comp){
	QuickSort_Comp(a, 0, n - 1, comp);
}

// Count time
int Partition(int* &a, int first, int last)
{
	int middle = (first + last) / 2;
	int pivot = a[middle];
	int i = first;
	int j = last;

	while (i <= j)
	{
		if (a[i] <= pivot)
		{
			i++;
		}
		else if (a[j] >= pivot)
		{
			j--;
		}
		else
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (middle < j)
	{
		swap(a[j], a[middle]);
		middle = j;
	}
	else if (middle > i)
	{
		swap(a[middle], a[i]);
		middle = i;
	}
	return middle;
}

void QuickSort(int* &a, int first, int last)
{
	if (first < last)
	{
		int pivotIndex = Partition(a, first, last);
		QuickSort(a, first, pivotIndex - 1);
		QuickSort(a, pivotIndex + 1, last);
	}
}

void QuickSortTime(int* &a, int n, double &elapsed_time)
{
	chrono::time_point<chrono::high_resolution_clock> start, end;
	start = chrono::high_resolution_clock::now();

	int first = 0;
	int last = n - 1;
	QuickSort(a, first, last);

	end = chrono::high_resolution_clock::now();
	elapsed_time = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1e6;
}

