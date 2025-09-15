#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/island-perimeter/

class Solution
{
    int cnt = 0;
    bool visited[1005][1005];
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;

    bool valid(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 && i >= n && j >= m && j < m && grid[i][j] == 1)
            return false;
        return true;
    }

    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        visited[i][j] = true;
        for (auto d : dir)
        {
            int ci = i + d.first;
            int cj = j + d.second;
            if (valid(ci, cj, grid) == false)
                cnt++;
            else if (valid(ci, cj, grid) == true && grid[ci][cj] == 0)
                cnt++;
            else if (valid(ci, cj, grid) == true && !visited[ci][cj] && grid[ci][cj] == 1)
                dfs(ci, cj, grid);
        }
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    // return accumulate(visited, visited + n * m, 0);
                }
            }
        }
        return 0;
    }
};
