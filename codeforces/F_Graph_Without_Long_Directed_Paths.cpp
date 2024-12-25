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
vector<int> adj[200005];
int color[200005];

bool bipa()
{
    bool is_bipartite = true;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        color[i] = -1;
    }
    for (int st = 1; st <= n; ++st)
    {
        if (color[st] == -1)
        {
            q.push(st);
            color[st] = 0;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int u : adj[v])
                {
                    if (color[u] == -1)
                    {
                        color[u] = color[v] ^ 1;
                        q.push(u);
                    }
                    else
                    {
                        is_bipartite &= color[u] != color[v];
                    }
                }
            }
        }
    }

    return is_bipartite;
}

void solve()
{
    cin >> n >> m;
    vector<pii> mp;
    loop(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        mp.pb(mk(u, v));
    }

    if (!bipa())
    {
        cout << "NO" << nL;
        return;
    }

    cout << "YES" << nL;
    loop(i, 0, m)
    {
        cout << color[mp[i].F];
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