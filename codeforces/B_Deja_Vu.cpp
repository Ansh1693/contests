#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), v;
    for (auto &i : a)
        cin >> i;

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (v.empty() || v.back() > x)
        {
            v.push_back(x);
        }
    }

    for (auto i : v)
    {
        int x = 1LL << i;
        int y = 1LL << (i - 1);
        for (int j = 0; j < n; j++)
        {
            if (a[j] % x == 0)
                a[j] += y;
        }
    }

    for (auto i : a)
        cout << i << " ";
    cout << endl;
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