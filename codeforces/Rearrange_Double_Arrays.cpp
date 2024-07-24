#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int maxi = 0;

    unordered_map<int, int> mp;

    bool ch = false;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > b[i])
        {
            ch = true;
            break;
        }

        mp[a[i]]++;

        maxi = max(maxi, mp[a[i]]);
    }

    if (ch || maxi > n + 1 / 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
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