// https://cses.fi/problemset/task/1097

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

    deque<int> q;

    int x;
    loop(i, 0, n)
    {
        cin >> x;
        q.pb(x);
    }

    vi dp(n, 0);
    if (q.front() > q.back())
    {
        dp[0] = q.front();
        q.pop_front();
    }
    else
    {
        dp[0] = q.back();
        q.pop_back();
    }

    if (q.front() > q.back())
    {
        dp[1] = q.front();
        q.pop_front();
    }
    else
    {
        dp[1] = q.back();
        q.pop_back();
    }

    loop(i, 2, n)
    {
        if (q.front() > q.back())
        {
            dp[i] = dp[i - 2] + q.front();
            q.pop_front();
        }
        else
        {
            dp[i] = dp[i - 2] + q.back();
            q.pop_back();
        }
    }

    for (auto it : dp)
    {
        cout << it << " ";
    }

    cout << nL;

    cout << max(dp[n - 1], dp[n - 2]) << nL;
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