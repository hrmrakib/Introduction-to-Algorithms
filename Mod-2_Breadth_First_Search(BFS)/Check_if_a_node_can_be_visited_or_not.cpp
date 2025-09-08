#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; // array of vector
bool visited[1005];

// o (v) -> space complexity
void bfs(int src) // o(v + e) -> vertex + edge (time complexity)
{
    queue<int> q;
    q.push(src);

    while (!q.empty()) //  o(n)
    {
        int parent = q.front();
        q.pop();

        for (int val : adj_list[parent]) // o(e) -> edge
        {
            if (visited[val] == false)
            {
                visited[val] = true;
                q.push(val);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    int a[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected graph
    }

    memset(visited, false, sizeof(visited));

    int src, dst;
    cin >> src >> dst;
    bfs(src);

    if (visited[dst] == true)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
