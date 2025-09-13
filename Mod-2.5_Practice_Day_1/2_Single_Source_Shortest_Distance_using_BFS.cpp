#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        // cout << parent << " ";

        for (int val : adj_list[parent])
        {
            if (!visited[val])
            {
                q.push(val);
                visited[val] = true;
                level[val] = level[parent] + 1;
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

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " => " << level[i] << "\n";
    // }

    cout << level[dst] << endl;

    return 0;
}
