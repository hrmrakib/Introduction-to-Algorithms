#include <bits/stdc++.h>
using namespace std;

char adj_list[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (adj_list[i][j] == '-')
        return false;
    return true;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;

    for (int k = 0; k < 4; k++)
    {
        int ci = si + dir[k].first;
        int cj = sj + dir[k].second;
        if (valid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj_list[i][j];
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    memset(visited, false, sizeof(visited));

    if (adj_list[si][sj] == '-' || adj_list[di][dj] == '-')
    {
        cout << "NO\n";
        return 0;
    }

    dfs(si, sj);

    if (visited[di][dj])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
