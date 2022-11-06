#include <chrono>
#include "..\Helper\Ultility.h"

using namespace std;

void ShakerSort(int* &a, int n)
{ 
	int left = 0;
	int right = n - 1;
	int k ;
	while (left < right)
	{
		// 23 24 17 16 25 26 30 28 32
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		right = k ;
		for (int i = right - 1; i >= left; i--)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		left = k;
	}
}

void ShakerSortComp(int* &a, int n, long long& comp)
{
	int left = 0;
	int right = n - 1;
	int k ;
	while ( ++comp && left < right)
	{
		for (int i = left; ++comp && i < right; i++)
		{

			if ( ++comp && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;

			}

		}

		right = k;
		for (int j = right - 1; ++comp && j >= left; j--)
		{
			if ( ++comp && a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k = j;
			}
		}
		left = k;
	}
}
void ShakerSortTime (int* &a, int n, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    ShakerSort(a,n);
    auto end = std::chrono::high_resolution_clock::now();
    time = double(chrono::duration_cast <chrono::nanoseconds> (end - start).count()) / 1e6;
}
