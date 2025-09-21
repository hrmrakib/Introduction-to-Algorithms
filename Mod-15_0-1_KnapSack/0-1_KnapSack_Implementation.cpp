#include <bits/stdc++.h>
using namespace std;

int val[1005], wt[1005];

int knapsack(int i, int max_weight)
{

    // base case
    if (i < 0 || max_weight <= 0)
        return 0;

    // recursive case
    if (wt[i] <= max_weight)
    {
        // options:
        // 1. not take the item
        // 2. take the item (if possible)

        int opt1 = knapsack(i - 1, max_weight - wt[i]) + val[i];
        int opt2 = knapsack(i - 1, max_weight);
        return max(opt1, opt2);
    }
    else
    {
        // only option is to not take the item
        return knapsack(i - 1, max_weight);
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

    knapsack(n - 1, maxWeight);

    cout << knapsack(n - 1, maxWeight) << endl;

    return 0;
}
