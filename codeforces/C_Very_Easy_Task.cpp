#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int n, x, y;
int main()
{

    cin >> n >> x >> y;

    n = n - 1;

    ll l = 0, r = max(x, y) * n;
    while (r > l + 1)
    {
        ll m = (l + r) / 2;
        if (m / x + m / y >= n)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << r + 1 << endl;

    return 0;
}