//29/10/2022
//cite: https://www.youtube.com/watch?v=CAaDJJUszvE&t=1109s
//cite: https://en.wikipedia.org/wiki/Flashsort
//cite: https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh
#include <chrono>
#include "..\Helper\Ultility.h"
#include "..\Algorithm\SortingAlgorithm.h"
using namespace std;

void FlashSortTime(int a[], int n, double &time){
	auto start = chrono::high_resolution_clock::now();   // Start measure time 

    //Step 1:
    //Set the number of bucket to size of array * 0.43
    //0.43 is said to be proven as the optimal bucket classifying key number
    //Even though I could not find any material that suggest any such number
    int m = int(0.43 * n);
    
    //Set up array for end of buckets
    int* L = new int[m];

    //Pre-populate the array 
    for(int i = 0; i < m; i++) L[i] = 0;
   
    //1.1. Find the minimum value and the index of the maximum element in the array
    int min = a[0], max = 0;

    int i = 0;
    while(i < n){
        if(min > a[i]) min = a[i];
        if(a[max] < a[i]) max = i;

        i++;
    }
    
    //1.2. Calculate the numer of element in each bucket
    double c1 = (m - 1)*1.0/(a[max] - min);

    i = 0;
    while(i < n){
        L[int(c1*(a[i] - min))]++;
        i++;
    }

    //1.3 Find the last element of each bucket
    i = 1;
    while(i < m){
        L[i] += L[i - 1];
        i++;
    }
    
    //Step 2: Move the element to the right bucket
    int nmove = 0;
    int j = 0;
    int k;
    int flash;

    while(nmove < n - 1){
        //Get the bucket of the current element
        k = int(c1*(a[j] - min));
        
        //If element at postition j is already at the right bucket
        //Move to the next element
        while (j > L[k] - 1){
            //Increase the array 
            j++;
            
            //Get the bucket of element of incremented element
            k = int(c1 * (a[j] - min));
        }

        //We've found the first unclassified elelement in bucket Lk
        //Save that element in t
        flash = a[j];

        //Start loop
        while(j != L[k]){
            //Find the bucket that t belongs to
            k = int(c1 * (flash - min));

            //Decrement Lk to show that Aj is correctly classify
            --L[k];

            //Exchange flash with element at the end of bucket
            swap(flash, a[L[k]]);

            //Increase element at the right bucket by 1
            ++nmove;
        }
    }

    //Step 3: Use insertion sort to sort the bucket 
    i = 1;
    while (i < n){
        flash = a[i];

        j = i - 1;
        while(j >= 0 && a[j] > flash){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = flash;

        i++;
    }

    
	auto end = chrono::high_resolution_clock::now();
	time = double(chrono::duration_cast <chrono::nanoseconds> (end - start).count()) / 1e6;
}

void FlashSortComp(int a[], int n, long long &comp){
    comp = 0;

    //Step 1:
    //Set the number of bucket to size of array * 0.43
    //0.43 is said to be proven as the optimal bucket classifying key number
    //Even though I could not find any material that suggest any such number
    int m = int(0.43 * n);
    
    //Set up array for end of buckets
    int* L = new int[m];

    //Pre-populate the array 
    for(int i = 0; ++comp && i < m; i++) L[i] = 0;
   
    //1.1. Find the minimum value and the index of the maximum element in the array
    int min = a[0], max = 0;

    int i = 0;
    while(++comp && i < n){
        if(++comp && min > a[i]) min = a[i];
        if(++comp && a[max] < a[i]) max = i;

        i++;
    }
    
    //1.2. Calculate the numer of element in each bucket
    double c1 = (m - 1)*1.0/(a[max] - min);

    i = 0;
    while(++comp && i < n){
        L[int(c1*(a[i] - min))]++;
        i++;
    }

    //1.3 Find the last element of each bucket
    i = 1;
    while(++comp && i < m){
        L[i] += L[i - 1];
        i++;
    }
    
    //Step 2: Move the element to the right bucket
    int nmove = 0;
    int j = 0;
    int k;
    int flash;

    while(++comp && nmove < n - 1){
        //Get the bucket of the current element
        k = int(c1*(a[j] - min));
        
        //If element at postition j is already at the right bucket
        //Move to the next element
        while (++comp && j > L[k] - 1){
            //Increase the array 
            j++;
            
            //Get the bucket of element of incremented element
            k = int(c1 * (a[j] - min));
        }

        //We've found the first unclassified elelement in bucket Lk
        //Save that element in t
        flash = a[j];

        //Start loop
        while(++comp && j != L[k]){
            //Find the bucket that t belongs to
            k = int(c1 * (flash - min));

            //Decrement Lk to show that Aj is correctly classify
            --L[k];

            //Exchange flash with element at the end of bucket
            swap(flash, a[L[k]]);

            //Increase element at the right bucket by 1
            ++nmove;
        }
    }

    //Step 3: Use insertion sort to sort the bucket 
    i = 1;
    while (++comp && i < n){
        flash = a[i];

        j = i - 1;
        while(++comp && j >= 0 && ++comp && a[j] > flash){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = flash;

        i++;
    }
}