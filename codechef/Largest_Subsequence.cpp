#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nL "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)

int n;
string s;

void solve()
{
    cin >> n >> s;

    int maxiLen = 0;
    loop(i, 0, n)
    {

        if (s[i] == s[n - 1])
        {
            maxiLen = max(maxiLen, n - i);
        }
    }

    loop(i, 0, n)
    {
        if (s[i] == s[0])
        {
            maxiLen = max(maxiLen, i + 1);
        }
    }

    cout << maxiLen << nL;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
