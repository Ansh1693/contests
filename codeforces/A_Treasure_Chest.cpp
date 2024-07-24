#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;

    int ans = 0;

    if (y < x)
    {
        ans += x;
    }
    else
    {
        int z = y - x;
        ans += x;

        if (z > k)
        {
            ans += k + 2 * (z - k);
        }
        else
        {
            ans += z;
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