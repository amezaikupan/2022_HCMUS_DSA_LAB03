#include <chrono>
#include "..\Helper\Ultility.h"

using namespace std;

void ShakerSort(int* &a, int n)
{
	//bool swaped= true; 
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		//swaped = false;
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				//swaped = true;
			}
		}
		right--;
		// if(!swaped)
		// {
		// 	return;
		// }
		// swaped = false;
		for (int i = right - 1; i >= left; i--)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				//swaped = true;
			}
		}
		left++;
	}
}

void ShakerSortComp(int* &a, int n, long long& comp)
{
	bool sorted = true; 
	int left = 0;
	int right = n - 1;
	while ( ++comp && left < right)
	{
		for (int i = left; ++comp && i < right; i++)
		{

			if ( ++comp && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);

			}

		}

		right--;
		for (int i = right - 1; ++comp && i >= left; i--)
		{
			if ( ++comp && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
			}
		}
		left++;
	}
}
void ShakerSortTime (int* &a, int n, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    ShakerSort(a,n);
    auto end = std::chrono::high_resolution_clock::now();
    time = double(chrono::duration_cast <chrono::nanoseconds> (end - start).count()) / 1e6;
}
