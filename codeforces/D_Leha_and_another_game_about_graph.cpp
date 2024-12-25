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
vector<int> adj[300005];
int a[300005];
int vis[300005];
map<pii, int> mp;
vi negs;
vi ans;

void dfs(int node, int par)
{
    for (auto i : adj[node])
    {
        if (par != i && !vis[i])
        {
            vis[i] = 1;
            dfs(i, node);
        }
    }

    if (par != -1)
    {
        if (a[node] == 1)
        {
            a[par] ^= 1;
            a[node] ^= 1;
            ans.pb(mp[mk(node, par)]);
        }
    }
}

void solve()
{
    cin >> n >> m;
    int sum = 0;
    int sum1 = 0;
    loop(i, 0, n)
    {
        cin >> a[i];
        if (a[i] != -1)
            sum += a[i];
        else
            negs.pb(i);
    }

    loop(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[mk(u, v)] = i + 1;
        mp[mk(v, u)] = i + 1;
    }
    if (negs.empty() && sum % 2 != 0)
    {
        cout << -1 << nL;
        return;
    }

    for (auto i : negs)
        a[i] = 0;

    if (sum % 2)
        a[negs[0]] = 1;

    vis[0] = 1;
    dfs(0, -1);

    cout << ans.size() << nL;
    for (auto i : ans)
        cout << i << nL;
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