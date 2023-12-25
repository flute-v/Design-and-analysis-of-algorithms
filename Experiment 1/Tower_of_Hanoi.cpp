#include <iostream>
#include<time.h>
using namespace std;

// Move a disk from 'src' to 'dest'
void moveDisk(int disk, char src, char dest)
{
    cout << "Move disk " << disk << " from " << src << " to " << dest << endl;
}

// Solve Tower of Hanoi for 'n' disks: move from 'src' to 'dest' using 'via'
void towerOfHanoi(int n, char src, char via, char dest)
{
    if (n == 1)
    {
        moveDisk(n, src, dest); // Move a single disk
        return;
    }

    towerOfHanoi(n - 1, src, dest, via); // Move (n-1) disks to 'via'
    moveDisk(n, src, dest);              // Move 1 disk to 'dest'
    towerOfHanoi(n - 1, via, src, dest); // Move (n-1) disks to 'dest'
}

int main()
{
    int numDisks;
    clock_t start, end;
    start = clock();
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    towerOfHanoi(numDisks, 'A', 'B', 'C');
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by program is : " << fixed
         << time_taken;
    return 0;
}
