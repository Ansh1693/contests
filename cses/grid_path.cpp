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
    int n;
    cin >> n;
    vvi arr(n, vi(n));
    loop(i, 0, n)
    {
        string s;
        cin >> s;
        loop(j, 0, n)
        {
            arr[i][j] = s[j];
        }
    }

    vvi dp(n, vi(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[n - 1][i] == '*')
            break;

        dp[n - 1][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i][n - 1] == '*')
            break;

        dp[i][n - 1] = 1;
    }

    for (int i = n - 2; i >= 0; i--)

    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (arr[i][j] != '*')
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
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

    cout << dp[0][0] << nL;
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