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
vi adj[100001];
int vis[100001];
int par[100001];
int st = -1, endd = -1;
void dfs(int nd)
{
    vis[nd] = 1;
    for (auto i : adj[nd])
    {
        if (vis[i] == 0)
        {
            dfs(i);
            par[i] = nd;
            if (st != -1)
            {
                return;
            }
        }
        else if (vis[i] == 1)
        {
            st = i;
            endd = nd;
            return;
        }
    }
    vis[nd] = 2;
}

void solve()
{
    memset(vis, 0, sizeof(vis));

    cin >> n >> m;
    int a, b;
    loop(i, 0, m)
    {
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    loop(i, 0, n)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }

    cout << st << " " << endd << nL;

    if (st == -1)
    {
        cout << "IMPOSSIBLE" << nL;
    }
    else
    {
        vi ans;
        ans.pb(st + 1);
        while (endd != st)
        {
            ans.pb(endd + 1);
            endd = par[endd];
        }
        reverse(all(ans));
        cout << ans.size() << nL;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << nL;
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