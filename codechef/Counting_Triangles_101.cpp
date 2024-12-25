#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MXN = 2e6 + 5;
const int mod = 1e9 + 7;

int pre[MXN];
int f[MXN];

int pw(int a, int b)
{
    a %= mod;
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int nck(int n, int k)
{
    if (min(n, k) < 0 || k > n)
        return 0;
    return (((f[n] * pw(f[n - k], mod - 2)) % mod) * pw(f[k], mod - 2)) % mod;
}

int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
    {
        pre[i] = (i ? pre[i - 1] : 0);
        pre[i] = (pre[i] + nck(i, n - 2)) % mod;
    }
    int res = 0;
    for (int i = 2; i <= m; i++)
    {
        int x = (i << 1) - 2;
        int cnt = i - 1;
        if (x > m)
        {
            int left = x - m;
            res = (res + ((min(left, cnt) * nck(m - i, n - 2)) % mod)) % mod;
            x -= min(left, cnt);
            cnt -= min(left, cnt);
        }
        if (!cnt)
            continue;
        res = (res + ((pre[x - i] - pre[x - cnt]) % mod) + mod) % mod;
    }
    cout << res << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    f[0] = 1;
    for (int i = 1; i < MXN; i++)
        f[i] = (f[i - 1] * i) % mod;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
