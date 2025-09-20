#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    const long long INF = 1e15;
    long long adj[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = (i == j ? 0 : INF);

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (adj[a][b] > c)
            adj[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj[i][k] != INF && adj[k][j] != INF && adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (adj[u][v] == INF)
            cout << "Not Possible\n";
        else
            cout << adj[u][v] << "\n";
    }

    return 0;
}
