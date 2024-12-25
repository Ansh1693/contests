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
string s[1001];
int ans = 0;
int cnt[26];

string na = "narek";

unordered_map<string, int> memo;

pii get(string s)
{
    memset(cnt, 0, sizeof(cnt));

    int pos = 0;
    int tot = 0;

    loop(i, 0, s.size())
    {
        if (s[i] == na[pos])
        {
            pos++;
            if (pos == 5)
            {
                tot++;
                pos = 0;
            }
        }

        cnt[s[i] - 'a']++;
    }

    int rem = 0;

    for (auto it : na)
    {
        rem += (cnt[it - 'a'] - tot);
    }

    return {tot * 5, rem};
}
int rec(int i, string curr)
{
    if (i == n)
    {
        pii p = get(curr);
        return p.F - p.S;
    }

    string key = curr;
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    int include = rec(i + 1, curr + s[i]);
    int exclude = rec(i + 1, curr);

    memo[key] = max(include, exclude);
    return memo[key];
}

// void solve()
// {
//     cin >> n >> m;
//     loop(i, 0, n)
//     {
//         cin >> s[i];
//     }

//     memset(dp, -1e9, sizeof(dp));
//     dp[0][0] = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int mask = 0; mask < (1 << 5); mask++)
//         {
//             dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);

//             pii p = get(s[i]);
//             int new_mask = mask;
//             dp[i + 1][new_mask] = max(dp[i + 1][new_mask], dp[i][mask] + p.F - p.S);
//         }
//     }

//     ans = 0;
//     for (int mask = 0; mask < (1 << 5); mask++)
//     {
//         ans = max(ans, dp[n][mask]);
//     }

//     cout << ans << nL;
// }

void solve()
{
    cin >> n >> m;
    loop(i, 0, n)
    {
        cin >> s[i];
    }

    memo.clear();
    ans = rec(0, "");
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