#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP_BINARY_KNAPSACK(vector<int> &V, vector<int> &W, int M)
{
    int n = V.size();
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            if (W[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], V[i - 1] + dp[i - 1][j - W[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][M];
}

int main()
{
    // Example usage:
    vector<int> V = {5, 3, 7, 10}; // Profit of items
    vector<int> W = {1, 3, 5, 7};  // Weight of items
    int M = 8;                     // Knapsack capacity
    clock_t start, end;
    start = clock();
    int maxProfit = DP_BINARY_KNAPSACK(V, W, M);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << time_taken<<endl;
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
