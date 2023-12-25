#include <iostream>  
#include<time.h>
using namespace std;  
  
void insert(int a[], int n) 
{  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])  
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
    }  
}  
  
  
int main()  
{  
    int a[] = { 89, 45, 35, 8, 12, 2 };  
    int n = sizeof(a) / sizeof(a[0]);  
    clock_t t = clock();
    insert(a, n);  
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout<<time_taken;

    return 0;  
}  
