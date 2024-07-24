#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    vector<int> a, b;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.push_back(x);
    }

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        arr.push_back({a[i] + b[i], i});
    }

    sort(arr.begin(), arr.end());

    ll res = 0, oper = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (oper % 2 == 0)
        {
            res += a[arr[i].second] - 1;
        }
        else
        {
            res -= b[arr[i].second] - 1;
        }

        oper++;
    }

    cout << res << endl;
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