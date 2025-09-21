#include <bits/stdc++.h>
using namespace std;

int parent[100005];
int parentSize[100005];

int find_parent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}

void union_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (parentSize[a] < parentSize[b]) swap(a, b);
        parent[b] = a;
        parentSize[a] += parentSize[b]; 
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        parentSize[i] = 1;
    }

    int cycle_edges = 0;

    while (e--) {
        int a, b;
        cin >> a >> b;

        int pa = find_parent(a);
        int pb = find_parent(b);

        if (pa == pb) {
            cycle_edges++;
        } else {
            union_sets(pa, pb);
        }
    }

    cout << cycle_edges << "\n";
    return 0;
}
