#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/max-area-of-island/

class Solution
{
public:
    bool visited[1005][1005];
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int n, m;

    bool vaild(int i, int j)
    {
        if (i < 0 && i >= n && j >= m && j < m)
            return false;
        return true;
    }

    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        visited[i][j] = true;
        for (int i = 0; i < 4; i++)
        {
            int ci = i + dir[i].first;
            int cj = j + dir[i].second;
            if (valid(ci, cj) && grid[ci][cj] == 1)
                dfs(ci, cj, grid);
            else if (valid(ci, cj, grid) == true && grid[ci][cj] == 0)
                continue;
            else if (valid(ci, cj, grid) == true && !visited[ci][cj] && grid[ci][cj] == 1)
                dfs(ci, cj, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                }
    }
};