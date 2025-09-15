#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (grid[i][j] == '#')
        return false;
    return true;
}

int dfs(int si, int sj)
{
    visited[si][sj] = true;
    int cnt = 1;

    for (int k = 0; k < 4; k++)
    {
        int ci = si + dir[k].first;
        int cj = sj + dir[k].second;

        if (valid(ci, cj) && !visited[ci][cj])
        {
            cnt += dfs(ci, cj);
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    vector<int> apartments;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                int room_count = dfs(i, j);
                apartments.push_back(room_count);
            }
        }
    }

    if (apartments.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(apartments.begin(), apartments.end());
        for (int val : apartments)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
