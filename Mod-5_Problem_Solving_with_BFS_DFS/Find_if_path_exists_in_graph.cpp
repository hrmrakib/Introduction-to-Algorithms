#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution
{
public:
    bool visited[200005];
    vector<int> adj_list[200005];

    void dfs(int src)
    {
        visited[src] = true;
        for (int child : adj_list[src])
        {
            if (visited[adj_list[src][child]] == false)
            {
                dfs(adj_list[src][child]);
            }
        }
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        memset(visited, false, sizeof(visited));
        dfs(source);

        if (visited[destination])
            return true;
        return false;
    }
};