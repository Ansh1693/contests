#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        int ans = x + y + z;

        if (ans >= 90)
            cout << "PASS" << endl;
        else
            cout << "FAIL" << endl;
    }

    return 0;
}