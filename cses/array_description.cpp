#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int n, m;
int a[100005];

void solve()
{
    cin >> n >> m;
    loop(i, 0, n) cin >> a[i];

    vvi dp(n, vi(m + 1, 0));

    if (a[0] == 0)
    {
        forEqual(i, 1, m) dp[0][i] = 1;
    }
    else
    {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;

                if (j - 1 >= 1)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= mod;
                }

                if (j + 1 <= m)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= mod;
                }
            }
        }
        else
        {
            dp[i][a[i]] += dp[i - 1][a[i]];
            dp[i][a[i]] %= mod;

            if (a[i] - 1 >= 1)
            {
                dp[i][a[i]] += dp[i - 1][a[i] - 1];
                dp[i][a[i]] %= mod;
            }

            if (a[i] + 1 <= m)
            {
                dp[i][a[i]] += dp[i - 1][a[i] + 1];
                dp[i][a[i]] %= mod;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << nL;
    // }
    int ans = 0;
    forEqual(i, 1, m)
    {
        ans += dp[n - 1][i];
        ans %= mod;
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