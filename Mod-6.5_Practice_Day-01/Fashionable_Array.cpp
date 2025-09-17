#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        int mn = arr[0];
        int mx = arr[n - 1];

        if (mn % 2 == mx % 2)
            cout << 0 << "\n";
        else
        {
            int i, cnt = 0;
            while (arr[i] % 2 != mx % 2)
            {
                i++;
            }

            int j = n - 1, cnt2 = 0;
            while (arr[j] % 2 != mn % 2)
            {
                j--;
                cnt2++;
            }

            cout << min(cnt, cnt2) << "\n";
        }
    }

    return 0;
}
