#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		
		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}

	
	return -1;
}

int main()
{
	
    int x = 1;
    int N = 10;
    int a[N];
    clock_t t = clock();

    for (int i = 1; i <= N; i++)
        a[i] = i;
    int result = binarySearch(a, 0, N - 1, x);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    cout << time_taken;


	return 0;
}
