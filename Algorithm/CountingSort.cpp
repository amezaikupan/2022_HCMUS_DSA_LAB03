#include <chrono>
#include "..\Helper\Ultility.h"

using namespace std;

void CountingSort(int* a, int n)
{

	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		else if (a[i] < min)
		{
			min = a[i];
		}

	} 
	int size = max - min + 1;
	int* count= new int[size]{0};
	int* result = new int[n];
	
	for (int i = 0; i < n; i++)
	{//
		count[a[i] - min]++;
	}
	//
	for (int i = 1; i < size; i++)
	{
		count[i] += count[i - 1];
	}
	//Rotate the count array by 1
	for (int i = size - 1 ; i > 0; i--)
	{
		count[i] = count[i - 1];
	}
	//count[0] = 0;
	count[0] = 0;
	for (int i = 0; i < n; i++)
	{
		result[count[a[i] - min]] = a[i];
		count[a[i] - min]++;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = result[i];
	}
	delete[] count;
	delete[] result;
}
void CountingSortCom(int* &a, int n, long long& comp)
{
	comp = 0;

	int max = 0;
	for (int i = 0; ++comp && i < n; i++)
	{
		if (++comp && a[i] > max)
		{
			max = a[i];
		}

	}

	int* count = new int[max + 1]{ 0 };
	int* result = new int[n];

	for (int i = 0; ++comp && i < n; i++)
	{
		count[a[i]]++;
	}

	for (int i = 1; ++comp && i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	//Rotate the count array by 1
	for (int i = max; ++comp && i > 0; i--)
	{
		count[i] = count[i - 1];
	}
	count[0] = 0;

	for (int i = 0; ++ comp && i < n; i++)
	{
		result[count[a[i]]] = a[i];
		count[a[i]]++;
	}
	
	for (int i = 0; ++comp &&  i < n; i++)
	{
		a[i] = result[i];
	}

	
	delete[] count;
	delete[] result;
}
void CountingSortTime(int * &a, int n, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    CountingSort(a,n);
    auto end = std::chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}