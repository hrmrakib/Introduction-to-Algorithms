#include <bits/stdc++.h>
using namespace std;

int n, m;
char adj_list[1005][1005];
bool visited[1005][1005];

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (adj_list[i][j] == '-')
        return false;
    if (visited[i][j])
        return false;
    return true;
}

int dfs(int si, int sj)
{
    stack<pair<int, int>> st;
    st.push({si, sj});
    visited[si][sj] = true;
    int area = 1;

    while (!st.empty())
    {
        pair<int, int> par = st.top();
        st.pop();

        for (int k = 0; k < 4; k++)
        {
            int ni = par.first + dir[k].first;
            int nj = par.second + dir[k].second;
            
            if (valid(ni, nj))
            {
                visited[ni][nj] = true;
                st.push({ni, nj});
                area++;
            }
        }
    }
    return area;
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

    memset(visited, false, sizeof(visited));

    int minArea = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj_list[i][j] == '.' && !visited[i][j])
            {
                int area = dfs(i, j);
                if (!found)
                {
                    minArea = area;
                    found = true;
                }
                else
                {
                    if (area < minArea)
                    {
                        minArea = area;
                    }
                }
            }
        }
    }

    if (found)
        cout << minArea << endl;
    else
        cout << -1 << endl;

    return 0;
}
