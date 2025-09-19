#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mst[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                adj_mst[i][j] = 0;
            else
                adj_mst[i][j] = INT_MAX;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mst[a][b] = c;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // adj_mst[i][j] = min(adj_mst[i][j], adj_mst[i][k] + adj_mst[k][j]);
                if (adj_mst[i][k] != INT_MAX && adj_mst[k][j] != INT_MAX && adj_mst[i][j] > adj_mst[i][k] + adj_mst[k][j])
                    adj_mst[i][j] = adj_mst[i][k] + adj_mst[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mst[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
