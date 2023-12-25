#include <iostream>
#include<time.h>
using namespace std;
void selection(int arr[], int n)
{
    int i, j, small;

    for (i = 0; i < n - 1; i++) 
    {
        small = i; 

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[small])
                small = j;
    
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}


int main()
{
    int x=1000;
    int a[x];
    clock_t t = clock();

    for(int i=0;i<x;i++)
        a[i]=i;
    int n = sizeof(a) / sizeof(a[0]);
    selection(a, n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout<<time_taken;
  

    return 0;
}
