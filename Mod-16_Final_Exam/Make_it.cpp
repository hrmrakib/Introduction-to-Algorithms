#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

bool canReach(long long n, long long target)
{
    if (n == target)
        return true;
    if (n > target)
        return false;

    if (dp[n] != -1)
        return dp[n];

    bool opt1 = canReach(n + 3, target);
    bool opt2 = canReach(n * 2, target);

    dp[n] = (opt1 || opt2);
    return dp[n];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long target;
        cin >> target;

        memset(dp, -1, sizeof(dp));

        if (canReach(1, target))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
