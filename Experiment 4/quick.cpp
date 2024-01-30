#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int x = 100000;
    int a[x];
    for (int i = 0; i < x; i++)
        a[i] = i;
    int n = sizeof(a) / sizeof(a[0]);
    clock_t start, end;
    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << time_taken;
    return 0;
}
