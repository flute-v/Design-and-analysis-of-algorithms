#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int fib(int x)
{
   if ((x == 1) || (x == 0))
   {
      return (x);
   }
   else
   {
      return (fib(x - 1) + fib(x - 2));
   }
}
int main()
{
   int i = 0, x = 30;
   clock_t start, end;

   start = clock();

   while (i < x)
   {
      fib(i);
      i++;
   }
   end = clock();
   double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
   cout << "\nTime taken by program is : " << fixed
        << time_taken;
   cout << " sec " << endl;

   return 0;
}
