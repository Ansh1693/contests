#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int w, h, n;

bool check(ll x)
{
    return (x / w) * (x / h) >= n;
}

int main()
{

    cin >> w >> h >> n;

    ll l = 0, r = 1;

    while (!check(r))
    {
        r *= 2;
    }

    while (r > l + 1)
    {
        ll m = (l + r) / 2;
        if (check(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << r << endl;

    return 0;
}