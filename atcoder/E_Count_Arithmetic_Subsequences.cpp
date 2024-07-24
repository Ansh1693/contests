// https://atcoder.jp/contests/abc362/tasks/abc362_e

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
const int MOD = 998244353;

void solve()
{
    int N;
    cin >> N;
    vi A(N);
    loop(i, 0, N) cin >> A[i];

    vector<vector<unordered_map<int, int>>> dp(N, vector<unordered_map<int, int>>(N + 1));

    for (int i = 0; i < N; ++i)
    {
        dp[i][1][0] = 1;
    }

    vector<int> result(N + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int d = A[i] - A[j];
            for (int k = 2; k <= N; ++k)
            {
                if (dp[j][k - 1].count(d))
                {
                    dp[i][k][d] = (dp[i][k][d] + dp[j][k - 1][d]) % MOD;
                }
            }
        }
        for (int k = 1; k <= N; ++k)
        {
            for (const auto &pair : dp[i][k])
            {
                result[k] = (result[k] + pair.second) % MOD;
            }
        }
    }

    for (int k = 1; k <= N; ++k)
    {
        cout << result[k] << " ";
    }
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
