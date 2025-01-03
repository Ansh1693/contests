// https://cses.fi/problemset/task/1744

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

void solve()
{
    int n, m;
    cin >> n >> m;

    vvi dp(n + 1, vi(m + 1, 0));

    loop(i, 1, n + 1)
    {
        loop(j, 1, m + 1)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {

                // x-cut
                dp[i][j] = INT_MAX;
                loop(k, 1, i)
                {
                    dp[i][j] = min(dp[i - k][j] + dp[k][j], dp[i][j]);
                }
                // y cut
                loop(k, 1, j)
                {
                    dp[i][j] = min(dp[i][j - k] + dp[i][k], dp[i][j]);
                }

                dp[i][j]++;
            }
        }
    }

    // loop(i, 0, n + 1)
    // {
    //     loop(j, 0, m + 1)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << nL;
    // }

    cout << dp[n][m] << nL;
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