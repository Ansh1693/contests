// https://cses.fi/problemset/task/2413

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

int dp[10000001][2];

void solve(int n)
{
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    dp[0][1] = 1;

    loop(i, 1, n)
    {
        dp[i][0] = ((4 * dp[i - 1][0]) % mod + dp[i - 1][1]) % mod;
        dp[i][1] = ((2 * dp[i - 1][1]) % mod + dp[i - 1][0]) % mod;
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
    int x, maxi = 0;
    deque<int> q;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        cin >> x;
        q.pb(x);
        maxi = max(maxi, x);
    }
    solve(maxi);

    while (!q.empty())
    {
        x = q.front();

        cout << (dp[x - 1][0] + dp[x - 1][1]) % mod << nL;
        q.pop_front();
    }
    return 0;
}