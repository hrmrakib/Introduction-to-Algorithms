#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    visited[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + dir[i].first;
        cj = sj + dir[i].second;

        if (!visited[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        { 
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    memset(visited, false, sizeof(visited));
    dfs(si, sj);
    return 0;
}
