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
int x;
map<int, vi> mp;
map<int, bool> vis;
int ans = 0;
void rec(int len)
{
    vis[len] = 1;
    ans = max(ans, len);
    for (auto i : mp[len + 1])
    {
        if (!vis[len + i])
        {
            // cout << len << " " << i << nL;
            rec(len + i);
        }
    }
}

void solve()
{
    ans = 0;
    cin >> n;
    loop(i, 1, n + 1)
    {
        cin >> x;
        mp[x + i].pb(i - 1);
    }

    // int ans = n;

    // loop(i, 0, n)
    // {
    //     if (mp.find(ans + 1) != mp.end())
    //     {
    //         cout << ans << " ";
    //         cout << mp[ans + 1] << nL;
    //         ans += mp[ans + 1];
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    rec(n);

    cout << ans << nL;
    mp.clear();
    vis.clear();
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