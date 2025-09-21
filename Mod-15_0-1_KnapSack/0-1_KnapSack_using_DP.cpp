#include <bits/stdc++.h>
using namespace std;

int val[1005], wt[1005];
int dp[1005][1005];

int knapsack(int i, int max_weight)
{

    // base case
    if (i < 0 || max_weight <= 0)
        return 0;

    if (dp[i][max_weight] != -1)
        return dp[i][max_weight];

    // recursive case
    if (wt[i] <= max_weight)
    {
        // options:
        // 1. not take the item
        // 2. take the item (if possible)

        int opt1 = knapsack(i - 1, max_weight - wt[i]) + val[i];
        int opt2 = knapsack(i - 1, max_weight);
        dp[i][max_weight] = max(opt1, opt2);
        return dp[i][max_weight];
    }
    else
    {
        // only option is to not take the item
        dp[i][max_weight] = knapsack(i - 1, max_weight);
        return dp[i][max_weight];
    }
}

int main()
{
    int n, maxWeight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cin >> maxWeight;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = -1;
        }
    }
    knapsack(n - 1, maxWeight);

    cout << knapsack(n - 1, maxWeight) << endl;

    return 0;
}
