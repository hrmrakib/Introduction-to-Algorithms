#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1005][1005];
int level[1005][1005];

vector<pair<int, int>> dir = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int bfs(int si, int sj, int ti, int tj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int r = par.first;
        int c = par.second;

        if (r == ti && c == tj)
            return level[r][c];

        for (int k = 0; k < 8; k++)
        {
            int ci = r + dir[k].first;
            int cj = c + dir[k].second;

            if (valid(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                level[ci][cj] = level[r][c] + 1;
                q.push({ci, cj});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        int si, sj, ti, tj;
        cin >> si >> sj;
        cin >> ti >> tj;

        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));

        int ans = bfs(si, sj, ti, tj);
        cout << ans << endl;
    }
    return 0;
}
