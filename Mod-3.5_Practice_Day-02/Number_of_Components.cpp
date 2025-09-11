#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; // array of vector
bool visited[1005];

void dfs(int src)
{
    // cout << src << " ";
    visited[src] = true;

    for (int val : adj_list[src])
    {
        if (visited[val] == false)
        {
            dfs(val);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected graph
    }

    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
