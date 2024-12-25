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
int n, q;
// int dp[10005][10005];
// int b[10005][3];

void solve()
{
    cin >> n >> q;
    vvi a(n, vi(3));
    loop(i, 0, n)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    }

    sort(a.begin(), a.end(), [](vi &x, vi &y)
         {
        if (x[0] == y[0])
        {
            return x[1]>y[1];
        }else{
            return x[0]>y[0];
        } });

    vvi queries(q, vi(3));
    loop(i, 0, q)
    {
        cin >> queries[i][0] >> queries[i][1];

        queries[i][2] = i;
    }

    if (n == 0)
    {
        loop(i, 0, q)
        {
            cout << 0 << nL;
        }

        return;
    }

    sortall(queries);
    reverse(all(queries));

    int j = 0;

    vector<int> curr(1e4 + 5), prev(1e4 + 5);
    vi ans(q);
    for (int i = 0; i < n; i++)
    {
        while (j < q && queries[j][0] >= a[i][0])
        {
            ans[queries[j][2]] = prev[queries[j][1]];
            j++;
        }

        for (int k = 0; k <= 1e4; k++)
        {
            if (k - a[i][2] >= 0)
            {
                curr[k] = max(curr[k], a[i][1] + prev[k - a[i][2]]);
            }
        }

        prev = curr;
    }

    while (j < q && queries[j][0] < a[n - 1][0])
    {
        ans[queries[j][2]] = prev[queries[j][1]];
        j++;
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << nL;
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