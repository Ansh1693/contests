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

    sort(a.begin(), a.end());

    int operations = 0;
    vector<long long> chosen_x;

    for (int i = 0; i < n - 1; ++i)
    {
        long long x = 2 * (a[i + 1] - a[i]);
        operations++;
        chosen_x.push_back(x);
    }

    cout << operations << endl;
    if (operations <= n && operations > 0)
    {
        for (int i = 0; i < operations; ++i)
        {
            cout << chosen_x[i] << " ";
        }
        cout << endl;
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