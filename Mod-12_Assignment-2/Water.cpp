// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n < 2) {
            cout << 0 << " " << 0 << "\n";
            continue;
        }

        long long max1 = LLONG_MIN, max2 = LLONG_MIN;
        int idx1 = -1, idx2 = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] > max1) {
                max2 = max1;
                idx2 = idx1;
                max1 = a[i];
                idx1 = i;
            } else if (a[i] > max2) {
                max2 = a[i];
                idx2 = i;
            }
        }

        int L = min(idx1, idx2);
        int R = max(idx1, idx2);
        cout << L << " " << R << "\n";
    }
    return 0;
}
