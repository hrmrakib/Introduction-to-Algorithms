#include <bits/stdc++.h>
using namespace std;

bool isPileOfWord(string a, string b)
{
    if (a.size() != b.size())
        return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        if (isPileOfWord(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
