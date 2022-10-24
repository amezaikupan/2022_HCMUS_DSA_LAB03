#include <iostream>
#include <chrono>
#include "DataGenerator.h"
#include "Resource.h"
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//Insertion Sort
void InsertionSortCom (int* a, int n, int & compare)
{
	int temp;
	for (int i = 0; ++compare && i < n; i++) 
	{
		temp = a[i];
		int j = i - 1;
		while (++compare && j >= 0 && ++compare && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}
void InsertionSortTime (int* a, int n, int& time)
{
	
    auto start = chrono::high_resolution_clock::now();
	int temp;
	for (int i = 0; i < n; i++) 
	{
		temp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
    auto end = std::chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//Bubble Sort
void BubbleSortCom (int* a, int n, int &compare)
{
	int i = 0;
	int j = n - 1;
	while(++compare && i < n - 1)
	{
		while(++compare && j > i)
		{
			if(++compare && a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
			}
			j = j - 1;
		}
		i = i + 1;
	}
	
}
void BubbleSortTime (int* a, int n, int& time)
{
    auto start = chrono::high_resolution_clock::now();
	int i = 0;
	int j = n - 1;
	while(i < n - 1)
	{
		while(j > i)
		{
			if(a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
			}
			j = j - 1;
		}
		i = i + 1;
	}
	auto end = std::chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//Selection Sort
void SelectionSortCom(int* arr, int n, int& compare)
{
	for (int i = 0; ++compare && i < n; i++)
	{
		int min = i;
		for (int j = i; ++ compare && j < n; j++)
		{
			if (++ compare && arr[j] > arr[min])
			{
				min = j;
			}
		}
		Swap(arr[min], arr[i]);
	}
}

void SelectionSortTime(int* arr, int n, int& time)
{
    
    auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i; ++ j < n; j++)
		{
			if (arr[j] > arr[min])
			{
				min = j;
			}
		}
		Swap(arr[min], arr[i]);
	}
    auto end = std::chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//Heap Sort
void HeapRebuild(int pos, int arr[], int n)
{
	int k = pos;
	int v = arr[k];
	bool isHeap = false;
	while (!isHeap && (2 * k + 1) < n)
	{
		int j = 2 * k + 1;
		if (j < n - 1)
		{
			if (arr[j] < arr[j + 1])
				j = j + 1;
		}
		if (arr[k] >= arr[j])
		{
			isHeap = true;
		}
		else
		{
			Swap(arr[k], arr[j]);
			k = j;
		}
	}
}
void HeapRebuildCom(int pos, int arr[], int n, int& compare)
{
	int k = pos;
	int v = arr[k];
	bool isHeap = false;
	while (++compare  && !isHeap && ++compare && (2 * k + 1) < n)
	{
		int j = 2 * k + 1;
		if (++compare && j < n - 1)
		{
			if (++compare && arr[j] < arr[j + 1])
				j = j + 1;
		}
		if (++compare && arr[k] >= arr[j])
		{
			isHeap = true;
		}
		else
		{
			Swap(arr[k], arr[j]);
			k = j;
		}
	}
}

void HeapContructionCom(int arr[], int n, int& compare)
{
	int mid = (n - 1) / 2;
	while (++compare && mid >= 0)
	{
		HeapRebuildCom(mid, arr, n, compare);
		mid = mid - 1;
	}
}
void HeapContruction(int arr[], int n)
{
	int mid = (n - 1) / 2;
	while (mid >= 0)
	{
		HeapRebuild(mid, arr, n);
		mid = mid - 1;
	}
}
void HeapSortCom(int arr[], int n, int& compare)
{
	HeapContructionCom(arr, n, compare);
	int r = n - 1;
	while (++compare && r > 0)
	{
		Swap(arr[0], arr[r]);
		HeapRebuildCom(0, arr, r, compare);
		r = r - 1;
	}
}
void HeapSortTime(int arr[], int n, int& time )
{
	
    auto start = chrono::high_resolution_clock::now();
	HeapContruction(arr, n);
	int r = n - 1;
	while (r > 0)
	{
		Swap(arr[0], arr[r]);
		HeapRebuild(0, arr, r);
		r = r - 1;
	}
	auto end = std::chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//MergeSort
void Merge(int a[], int left, int mid, int right)
{
	int k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* Left = new int[n1];
	int* Right = new int[n2];
	for (int i = 0; i < n1; i++)
		Left[i] = a[left + i];
	for (int j = 0; j < n2; j++)
		Right[j] = a[mid + 1 + j];
	int i = 0;
	int j = 0;
	k = left;
	// 1 4 8    2 3
	//1 2 3
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			a[k] = Left[i];
			i++;
		}
		else
		{
			a[k] = Right[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = Left[i];
		i++;
		k++;

	}
	while (j < n2)
	{
		a[k] = Right[j];
		j++;
		k++;

	}
}
void MergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}
//Quick Sort
//27 38 12 39 27 16
//27 12 28 39 27 16
int Partition(int a[], int first, int last)
{
	int pivot = first;
	int lastS1 = first;//0
	int firstUnknown = first + 1;//1 2 3 4 5 
	while (firstUnknown <= last)
	{
		if (a[firstUnknown] < a[pivot])
		{
			Swap(a[firstUnknown], a[lastS1 + 1]);
			lastS1++;
			firstUnknown++;
		}
		else
		{
			firstUnknown++;
		}
	}
	Swap(a[lastS1], a[first]);
	pivot = lastS1;
	return pivot;
}
void QuickSort(int a[], int first, int last)
{
	if (first < last)
	{

		int pivot = Partition(a, first, last);
		QuickSort(a, first, pivot - 1);
		QuickSort(a, pivot + 1, last);
	}
}
//Radix Sort
int* RadixSort(int* arr, int n)
{
	int exp;
	int temp = arr[0];
	int* res = NULL;
	res = new int[n];
	for (exp = 1; arr[0] / exp > 0; exp *= 10)
	{
		int result[10][10] = {0};
		/*int** result = new int* [n];
		for (int i = 0; i < n; i++)
		{
			result[i] = new int[10];
		}*/
		int count[10] = { 0 };
		for (int h = 0; h < n; h++)
		{
			int k = (arr[h] / exp) % 10;
			result[count[k]][k] = arr[h];
			count[k] ++;
		}
		//0 0 12 23 33 0 0 16 37 0 19
		// 0 0 22
		int j = 0;
		int i = 0;
		while (j < 10)//j 2
		{
			int dem = 0;
			while (dem <= count[j] - 1)
			{
				res[i] = result[dem][j];
				dem++;
				i++;
			}
			j++;
		}
		for (int k = 0; k < i; k++)
		{
			arr[k] = res[k];
		}
	}
	delete[] res;
	
	return arr;
}
