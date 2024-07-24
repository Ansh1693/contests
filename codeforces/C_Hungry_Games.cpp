#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define aint(x) (x).begin(), (x).end()
#define forEqual(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b - 1; i >= a; i--)
#define sortaint(x) sort(aint(x))
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
    int n, x;
    cin >> n >> x;

    vi a(n);
    vi pre(n + 1, 0);
    loop(i, 0, n)
    {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }

    vi dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i)
    {
        int sum = pre[i] + x;

        auto lb = lower_bound(pre.begin(), pre.end(), sum) - pre.begin();

        if (lb == n + 1)
            dp[i] += (n - i);
        else if (sum == pre[lb])
            dp[i] += (lb - i) + dp[lb + 1];
        else
            dp[i] += (lb - i - 1) + dp[lb];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << dp[i] << " ";
        ans += dp[i];
    }
    // cout << nL;
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
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
