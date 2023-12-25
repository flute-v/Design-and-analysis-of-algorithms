#include<iostream>
using namespace std;
void fun2();
void fun1()
{
    cout<<"Function 1 starts"<<endl;
    for(int i=0;i<100000;i++);
    cout<<"function 1 ends"<<endl;
}
int main()
{
    cout<<"MAIN FUNCTION\n";
    fun1();
    fun2();
    return 0;
}
