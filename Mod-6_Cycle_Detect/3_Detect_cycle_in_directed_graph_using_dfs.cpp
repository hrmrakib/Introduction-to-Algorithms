#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005 + 1];
bool pathvisited[1005 + 1];
bool visited[1005 + 1];
bool cycle;

void dfs(int src)
{
    visited[src] = true;
    pathvisited[src] = true;

    for (int child : adj_list[src])
    {
        if (visited[child] && pathvisited[child])
        {
            cycle = true;
        }
        if (!visited[child])
        {
            dfs(child);
        }
    }

    pathvisited[src] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    memset(visited, false, sizeof(visited));
    memset(pathvisited, false, sizeof(pathvisited));

    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    if (cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
