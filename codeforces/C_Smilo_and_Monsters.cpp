#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        count += v[i];
    }

    sort(v.rbegin(), v.rend());

    int temp2 = 0, res = count;
    for (int i = 0; i < n; i++)
    {
        temp2 += v[i];
        count -= v[i];
        int temp = 0;
        if (temp2 > count)
        {
            temp = temp2 - count;
            temp = (temp + 1) / 2;
        }
        res = min(res, 1 + i + count + temp);
    }
    cout << res << endl;
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