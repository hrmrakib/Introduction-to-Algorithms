#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for (int val : adj_list[parent])
        {
            if (!visited[val])
            {
                q.push(val);
                visited[val] = true;
            }
        }
    }
}

void dfs(int src)
{
    cout << src << " ";
    visited[src] = true;

    for (int val : adj_list[src])
    {
        if (!visited[val])
        {
            dfs(val);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src;
    cin >> src;

    memset(visited, false, sizeof(visited));
    // bfs(src);
    dfs(src);

    return 0;
}