#include <bits/stdc++.h>
using namespace std;

int n, m;
char adj_list[1005][1005];
bool visited[1005][1005];
pair<int, int> parent[1005][1005];
int si, sj, di, dj;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (adj_list[i][j] == '#' || visited[i][j])
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    parent[si][sj] = {-1, -1};

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        if (x == di && y == dj)
            return;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (valid(nx, ny))
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
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
            if (adj_list[i][j] == 'R')
                si = i, sj = j;
            if (adj_list[i][j] == 'D')
                di = i, dj = j;
        }
    }

    memset(visited, false, sizeof(visited));
    bfs(si, sj);

    if (visited[di][dj])
    {
        pair<int, int> cur = {di, dj};
        while (!(cur.first == si && cur.second == sj))
        {
            pair<int, int> p = parent[cur.first][cur.second];
            if (adj_list[p.first][p.second] == '.')
                adj_list[p.first][p.second] = 'X';
            cur = p;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << adj_list[i][j];
        cout << "\n";
    }

    return 0;
}
