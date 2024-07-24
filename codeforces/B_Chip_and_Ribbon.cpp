#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int ans = arr[0] - 1;

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] - arr[i - 1] > 0)
        {
            ans += arr[i] - arr[i - 1];
        }
    }

    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}