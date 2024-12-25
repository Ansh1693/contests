#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nL "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    int zeroCount = 0, oneCount = 0;

    loop(i, 0, n)
    {
        if (s[i] == '0')
            zeroCount++;
        else
            oneCount++;
        if (t[i] == '0')
            zeroCount--;
        else
            oneCount--;
    }

    if (zeroCount % 2 == 0 && oneCount % 2 == 0)
    {
        cout << "YES" << nL;
    }
    else
    {
        cout << "NO" << nL;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        solve();
    }

    return 0;
}
