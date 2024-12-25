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

int n;
int a[300005];
int ans = 0;

// bool skipped = 1;

// vector<vvi> dp;

// void dfs(int i, int curr, bool skip, bool canSkip)
// {
//     if (i == n)
//     {
//         if (curr > ans)
//         {
//             ans = curr;
//             skipped = canSkip;
//         }
//         return;
//     }

//     int add = a[i] > curr ? 1 : (a[i] == curr ? 0 : -1);
//     dfs(i + 1, curr + add, 0, canSkip);

//     if (canSkip)
//     {
//         dfs(i + 1, curr, 1, 0);
//     }

//     if (skip)
//     {
//         dfs(i + 1, curr, 1, 0);
//     }
// }

void solve()
{
    ans = 0;
    cin >> n;
    loop(i, 0, n) cin >> a[i];

    // dfs(0, 0, 0, 1);

    vector<vvi> dp(n + 1, vvi(2, vi(2, -1)));
    // only valid
    //  000 001 010

    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    dp[0][0][1] = 0;
    loop(i, 1, n + 1)
    {
        loop(j, 0, 2)
        {
            loop(k, 0, 2)
            {
                if (j == 1 && k == 1)
                    continue;

                if (j == 0 && k == 0)
                {
                    int op1 = dp[i - 1][0][0];
                    int op2 = dp[i - 1][1][0];
                    op1 += (a[i - 1] > op1) ? 1 : (a[i - 1] == op1) ? 0
                                                                    : -1;
                    op2 += (a[i - 1] > op2) ? 1 : (a[i - 1] == op2) ? 0
                                                                    : -1;

                    dp[i][j][k] = max(op1, op2);
                }

                if (j == 1 && k == 0)
                {
                    int op1 = dp[i - 1][1][0];
                    int op2 = dp[i - 1][0][1];
                    dp[i][j][k] = max(op1, op2);
                }
                if (j == 0 && k == 1)
                {
                    int op1 = dp[i - 1][0][1];
                    op1 += (a[i - 1] > op1) ? 1 : (a[i - 1] == op1) ? 0
                                                                    : -1;

                    dp[i][j][k] = op1;
                }
            }
        }
    }

    int ans = max({dp[n][0][0], dp[n][1][0], dp[n][0][1]});

    if (ans == n)
        ans--;

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