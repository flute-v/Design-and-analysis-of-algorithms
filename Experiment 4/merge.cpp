#include <iostream>
#include <time.h>
using namespace std;
void M(int a[], int l, int m, int r)
{
    int result[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
            result[k++] = a[i++];
        else
            result[k++] = a[j++];
    }
    while (i <= m)
        result[k++] = a[i++];
    while (j <= r)
        result[k++] = a[j++];

    for (int i = l; i <= r; i++)
        a[i] = result[i - l];
}
void Merge(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        Merge(a, l, mid);
        Merge(a, mid + 1, r);
        M(a, l, mid, r);
    }
}
int main()
{

    int x = 1000;
    int a[x];
    for (int i = 0; i < x; i++)
        a[i] = i;
    int n = sizeof(a) / sizeof(a[0]);
    clock_t start, end;
    start = clock();
    Merge(a, 0, n - 1);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << time_taken;
}
