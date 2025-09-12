#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; // array of vector
bool visited[1005];

// o (v) -> space complexity
void bfs(int src) // o(v + e) -> vertex + edge (time complexity)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) //  o(n)
    {
        // ber kore ana
        int parent = q.front();
        q.pop();

        // oi node niya kaj kora
        cout << parent << " ";

        // children gulo push kora
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

    bfs(0);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int val : adj_list[i])
    //     {
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}
