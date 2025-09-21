#include <bits/stdc++.h>
using namespace std;

bool isPileOfWord(const string &a, const string &b) {
    if (a.length() != b.length()) return false;
    string x = a, y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return x == y;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (isPileOfWord(s1, s2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
