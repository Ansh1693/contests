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
string s;
int n;

int dp[100005][9];

void solve()
{
    cin >> s;
    n = s.size();
    int sm = 0;
    bool ch = 0;
    loop(i, 0, n)
    {
        sm += s[i] - '0';

        if (s[i] < '4' && s[i] > '1')
            ch = 1;
    }
    if (sm % 9 == 0)
    {
        cout << "YES" << nL;
        return;
    }
    if (!ch)
    {
        cout << "NO" << nL;
        return;
    }

    vvi dp(n + 1, vi(9, 0));

    loop(i, 0, 9)
    {
        dp[0][i] = 0;
    }

    dp[0][0] = 1;

    loop(i, 0, n)
    {
        int dig = s[i] - '0';
        int dig2 = 0;
        if (dig > 1 && dig < 4)
            dig2 = dig * dig;
        loop(j, 0, 9)
        {
            dp[i + 1][(j + dig) % 9] = max(dp[i + 1][(j + dig) % 9], dp[i][j]);

            if (dig2)
                dp[i + 1][(j + dig2) % 9] = max(dp[i + 1][(j + dig2) % 9], dp[i][j]);
        }
    }

    if (dp[n][0] > 0)
        cout << "YES" << nL;
    else
        cout << "NO" << nL;
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