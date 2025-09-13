#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout << parent << " ";

        for (int val : adj_list[par])
        {
            if (!visited[val])
            {
                q.push(val);
                visited[val] = true;
                level[val] = level[par] + 1;
                parent[val] = par;
            }
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
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    vector<int> path;
    int node = dst;
    while (node != src)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
