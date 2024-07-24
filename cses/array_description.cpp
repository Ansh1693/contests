// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define forEqual(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b - 1; i >= a; i--)
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef unordered_set<int> usi;
typedef set<int> si;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, bool> umib;
typedef unordered_map<string, bool> umsb;
typedef unordered_map<string, vi> umsvi;
typedef unordered_map<int, vi> umivi;
typedef map<int, int> mii;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vi value(n);

    loop(i, 0, n) cin >> value[i];

    vvi dp(n, vi(m + 1, 0));

    if (value[0] == 0)
    {
        loop(i, 1, m + 1)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][value[0]] = 1;
    }

    loop(i, 1, n)
    {
        loop(j, 1, m + 1)
        {
            if (value[i] != j && value[i] != 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = ((dp[i - 1][j]) % mod + (dp[i - 1][j - 1]) % mod) % mod;
                if (j + 1 < m + 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
    }

    // for (auto it : dp)
    // {
    //     for (auto it2 : it)
    //     {
    //         cout << it2 << " ";
    //     }

    //     cout << nL;
    // }
    int ans = 0;

    loop(i, 1, m + 1)
    {
        ans = (ans + dp[n - 1][i]) % mod;
    }

    cout << ans << nL;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    // #endif
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}