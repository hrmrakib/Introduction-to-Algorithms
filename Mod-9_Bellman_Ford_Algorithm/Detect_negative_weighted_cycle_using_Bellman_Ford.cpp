#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
int dist[1005];
vector<Edge> edge_list;

void bellmanFord() // o(v * e)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edge_list)
        {
            int a, b, c;
            a = edge.a;
            b = edge.b;
            c = edge.c;

            if (dist[a] != INT_MAX && dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }
        }
    }

    bool cycle = false;
    for (auto edge : edge_list)
    {
        int a, b, c;
        a = edge.a;
        b = edge.b;
        c = edge.c;

        if (dist[a] != INT_MAX && dist[a] + c < dist[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative Weighted Cycle Detected\n";
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dist[i] << "\n";
    }
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); // undirected
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    bellmanFord();

    return 0;
}
