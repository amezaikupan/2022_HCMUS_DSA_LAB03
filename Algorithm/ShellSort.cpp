#include <chrono>
using namespace std;


void ShellSortTime(int* &a, int n, double &time){
    auto start = chrono::high_resolution_clock::now();

    int i, j, gap = n / 2;
    
    i = gap;

    while(gap > 0){
        
        i = gap;

        while(i < n){
            int temp = a[i];

            j = i;
            while(j >= gap && a[j - gap] > temp){
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = temp;

            i++;
        }

        gap /= 2;
    }

    auto stop = chrono::high_resolution_clock::now();
    time = double(chrono::duration_cast <chrono::nanoseconds> (stop - start).count()) / 1e6;
}

void ShellSortComp(int* &a, int n, long long &comp){
    comp = 0;

    int i, j, gap = n / 2;
    i = gap;

    while(++comp && gap > 0){
        
        i = gap;

        while(++comp && i < n){
            int temp = a[i];

            j = i;
            while(++comp && j >= gap && ++comp && a[j - gap] > temp){
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = temp;

            i++;
        }

        gap /= 2;
    }
}