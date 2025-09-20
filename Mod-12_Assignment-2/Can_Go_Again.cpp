#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
long long dist[1005];
vector<Edge> edge_list;
const long long INF = (long long)1e18;

bool bellmanFord(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0LL;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto edge : edge_list)
        {
            int a = edge.a;
            int b = edge.b;
            long long c = edge.c;

            if (dist[a] != INF && dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }
        }
    }

    for (auto edge : edge_list)
    {
        int a = edge.a;
        int b = edge.b;
        long long c = edge.c;

        if (dist[a] != INF && dist[a] + c < dist[b])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    int t;
    cin >> t;
    vector<int> queries(t);
    for (int i = 0; i < t; i++)
        cin >> queries[i];

    if (!bellmanFord(src))
    {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    for (int i = 0; i < t; i++)
    {
        int d = queries[i];
        if (dist[d] == INF)
            cout << "Not Possible\n";
        else
            cout << dist[d] << "\n";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Edge
// {
// public:
//     int a, b;
//     long long c;
//     Edge(int a, int b, long long c)
//     {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//     }
// };

// int n, e;
// long long dist[1005];
// vector<Edge> edge_list;

// bool bellmanFord(int src)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         dist[i] = INT_MAX;
//     }
//     dist[src] = 0;

//     for (int i = 1; i <= n - 1; i++)
//     {
//         for (auto edge : edge_list)
//         {
//             int a = edge.a;
//             int b = edge.b;
//             long long c = edge.c;

//             if (dist[a] != INT_MAX && dist[a] + c < dist[b])
//             {
//                 dist[b] = dist[a] + c;
//             }
//         }
//     }

//     for (auto edge : edge_list)
//     {
//         int a = edge.a;
//         int b = edge.b;
//         long long c = edge.c;

//         if (dist[a] != INT_MAX && dist[a] + c < dist[b])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     cin >> n >> e;

//     while (e--)
//     {
//         int a, b;
//         long long c;
//         cin >> a >> b >> c;
//         edge_list.push_back(Edge(a, b, c));
//     }

//     int src;
//     cin >> src;

//     int t;
//     cin >> t;

//     if (!bellmanFord(src))
//     {
//         cout << "Negative Cycle Detected\n";
//         return 0;
//     }

//     while (t--)
//     {
//         int d;
//         cin >> d;
//         if (dist[d] == INT_MAX)
//             cout << "Not Possible\n";
//         else
//             cout << dist[d] << "\n";
//     }

//     return 0;
// }
