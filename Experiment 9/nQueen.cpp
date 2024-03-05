#include <iostream>
using namespace std;

int x[999];

bool place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
            return false;
    }
    return true;
}

int nQueen(int k, int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i) == true)
        {
            x[k] = i;
            if (k == n)
            {
                count++;
            }
            else
            {
                count += nQueen(k + 1, n);
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "nQueen problem" << endl;
    cout << "Enter n here: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
        x[i] = 0;

    int totalSolutions = nQueen(1, n);
    cout << "\npossible solutions are: " << totalSolutions << endl;

    return 0;
}
