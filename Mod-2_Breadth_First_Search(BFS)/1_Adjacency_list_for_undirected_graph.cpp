#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    int a[n];
    vector<int> adj_list[n]; // array of vector

    while(e--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected graph
    }
 
    for(int i = 0; i < n; i++) {
        cout << i << " -> "; 
        for(int val : adj_list[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}