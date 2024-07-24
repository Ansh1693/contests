// /https://cses.fi/problemset/task/1140

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

int helper(int i, bool free, int n, vi &st, vi &en, vi &pro)
{
    if (i == n)
    {
        return 0;
    }
    int ans = 0;
    if (free)
    {
        ans = max(ans, pro[i] + helper(i + 1, false, n, st, en, pro));
    }
    else
    {
        ans = max(ans, helper(i + 1, true, n, st, en, pro));
    }
    return ans;
}

int binsearch(int st, vi &arr, int en, int ele)
{
    int ans = -1;
    while (st <= en)
    {
        int mid = st + (en - st) / 2;
        if (arr[mid] < ele)
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vi st(n), en(n), pro(n);
    vector<pair<int, pair<int, int>>> v;
    loop(i, 0, n)
    {
        cin >> st[i] >> en[i] >> pro[i];
        v.pb({en[i], {st[i], pro[i]}});
    }
    sort(all(v));

    loop(i, 0, n)
    {
        en[i] = v[i].F;
        st[i] = v[i].S.F;
        pro[i] = v[i].S.S;
        // cout << "st:" << " " << st[i] << " " << "en:" << " " << en[i] << " " << "cost:" << " " << pro[i] << nL;
    }

    vi dp(n, 0);
    dp[0] = pro[0];
    loop(i, 1, n)
    {

        int idx = binsearch(0, en, i - 1, st[i]);
        if (idx != -1)
        {
            dp[i] = max(dp[i - 1], pro[i] + dp[idx]);
        }
        else
        {
            dp[i] = max(dp[i - 1], pro[i]);
        }
    }

    // for (auto it : dp)
    //     cout << it << " ";

    // cout << nL;

    cout << dp[n - 1] << nL;
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