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
int n, k, d;
vector<pii> adj[300005];
bool vis[300005];
bool edge[300005];
int x, y;

void solve()
{
    cin >> n >> k >> d;
    queue<pii> q;
    loop(i, 0, n + 1)
    {
        adj[i].clear();
        vis[i] = 0;
    }
    loop(i, 0, k)
    {
        cin >> x;
        q.push({x, 0});
    }
    loop(i, 0, n - 1)
    {
        cin >> x >> y;
        adj[x].pb({y, i});
        adj[y].pb({x, i});

        edge[i] = true;
    }

    while (!q.empty())
    {
        pii p = q.front();
        q.pop();

        if (vis[p.F])
            continue;

        vis[p.F] = 1;

        for (pii i : adj[p.F])
        {
            if (i.first == p.second)
                continue;

            if (vis[i.F])
                edge[i.S] = false;
            else
                q.push({i.F, p.F});
        }
    }

    int ans = 0;
    loop(i, 0, n - 1)
    {
        if (!edge[i])
            ans++;

        // cout << edge[i] << " ";
    }

    cout << ans << nL;

    loop(i, 0, n - 1)
    {
        if (!edge[i])
            cout << i + 1 << " ";
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