#include <bits/stdc++.h>
using namespace std;

int main() {
    int node, edge;
    cin  >> node >> edge;
    int adj_matrix[node][node];

    // for (int i = 0; i < node; i++)
    // {
    //     for (int j = 0; j < node; j++)
    //     {
    //         adj_matrix[i][j] = 0;
    //     }
    // }

    // shortcut of nested loop
    memset(adj_matrix, 0, sizeof(adj_matrix));

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if(i == j) {
                adj_matrix[i][j] = 1;
            }
        }
    }

    while(edge--) {
        int a, b;
        cin >> a >> b;
        adj_matrix[a][b] = 1;
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
} 