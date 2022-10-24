#pragma once
void Swap(int& a, int& b);
void InsertionSortCom (int* a, int n, int & compare);
void InsertionSortTime (int* a, int n, int& time);
void BubbleSortCom (int* a, int n, int &compare);
void BubbleSortTime (int* a, int n, int& time);
void SelectionSortCom(int* arr, int n, int& compare);
void SelectionSortTime(int* arr, int n, int& time);
void HeapRebuildCom(int pos, int arr[], int n);
void HeapRebuild(int pos, int arr[], int n);
void HeapContructionCom(int arr[], int n, int& compare);
void HeapContruction(int arr[], int n);
void HeapSortCom(int arr[], int n, int& compare);
void HeapSortTime(int arr[], int n, int& time );
void Merge(int a[], int left, int mid, int right);
void MergeSort(int a[], int left, int right);
int Partition(int a[], int first, int last);
void QuickSort(int a[], int first, int last);
int* RadixSort(int* arr, int n);
