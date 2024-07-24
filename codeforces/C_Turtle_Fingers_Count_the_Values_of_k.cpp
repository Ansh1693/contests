#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    ll a, b, l;
    cin >> a >> b >> l;

    int powA = 1;
    int a1 = a;
    int powB = 1;
    int b1 = b;
    while (a1 < l)
    {
        if (l % a1 == 0)
        {
            powA++;
        }
        else
            break;
        a1 *= a;
    }

    while (b1 < l)
    {
        if (l % b1 == 0)
        {

            powB++;
        }
        else
            break;
        b1 *= b;
    }

    unordered_map<ll, ll> mp;

    for (int i = 0; i <= powA; i++)
    {
        for (int j = 0; j <= powB; j++)
        {
            ll t = pow(a, i) * pow(b, j);

            if (t <= l && l % t == 0)
            {
                mp[l / t]++;
            }
        }
    }

    cout << mp.size() << endl;
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