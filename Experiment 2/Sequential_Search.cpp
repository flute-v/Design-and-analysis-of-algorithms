#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
using namespace std;

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int x = 500000;
    int N = 1000000;
    int a[N];
    clock_t t = clock();

    for (int i = 1; i <= N; i++)
        a[i] = i;
        
    int result = search(a, N, x);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    cout << time_taken;
    
    return 0;
}
