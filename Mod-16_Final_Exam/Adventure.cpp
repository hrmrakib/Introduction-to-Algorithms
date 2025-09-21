#include <bits/stdc++.h>
using namespace std;

int wt[1005], val[1005];
int dp[1005][1005];

int knapsack(int i, int cap)
{
    if (i < 0 || cap <= 0)
        return 0;

    if (dp[i][cap] != -1)
        return dp[i][cap];

    if (wt[i] <= cap)
    {
        int opt1 = val[i] + knapsack(i - 1, cap - wt[i]);
        int opt2 = knapsack(i - 1, cap);
        dp[i][cap] = max(opt1, opt2);
    }
    else
    {
        dp[i][cap] = knapsack(i - 1, cap);
    }

    return dp[i][cap];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, W;
        cin >> n >> W;

        for (int i = 0; i < n; i++)
            cin >> wt[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= W; j++)
                dp[i][j] = -1;

        cout << knapsack(n - 1, W) << endl;
    }

    return 0;
}
