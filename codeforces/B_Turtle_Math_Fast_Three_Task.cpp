#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    ll x;
    vector<ll> v(3, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[x % 3]++;
        sum += x;
    }

    if (sum % 3 == 0)
    {
        cout << "0\n";
    }
    else if (sum % 3 == 2)
    {
        cout << "1\n";
    }
    else
    {
        if (v[1] >= 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
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