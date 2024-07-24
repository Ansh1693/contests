#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a, b, c;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back({x, i + 1});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.push_back({x, i + 1});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        c.push_back({x, i + 1});
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    int ans = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (a[i].second != b[j].second && b[j].second != c[k].second && c[k].second != a[i].second)
                {
                    ans = max(ans, a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}