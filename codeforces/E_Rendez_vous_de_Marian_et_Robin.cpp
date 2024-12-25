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

int n, m, h;
vector<pii> adj[200005];
set<int> horses;

vvi dijkstra(int start)
{
    vvi dist(n + 1, vi(2, 1e18));
    dist[start][0] = 0;
    priority_queue<vi, vvi, greater<vi>> pq;
    pq.push({0, start, 0});

    while (!pq.empty())
    {
        auto it = pq.top();
        int d = it[0];
        int node = it[1];
        int st = it[2];
        pq.pop();

        if (d > dist[node][st])
            continue;

        if (st == 0 && horses.count(node))
        {
            if (dist[node][1] > d)
            {
                dist[node][1] = d;
                pq.push({d, node, 1});
            }
        }

        for (auto &[v, w] : adj[node])
        {
            int nd;
            if (st == 1)
            {
                nd = d + w / 2;
                if (nd < dist[v][1])
                {
                    dist[v][1] = nd;
                    pq.push({nd, v, 1});
                }
            }
            else
            {
                nd = d + w;
                if (nd < dist[v][0])
                {
                    dist[v][0] = nd;
                    pq.push({nd, v, 0});
                }
            }
        }
    }
    return dist;
}

void solve()
{
    cin >> n >> m >> h;

    horses.clear();
    loop(i, 1, n + 1) adj[i].clear();
    int hs;

    loop(i, 0, h)
    {
        cin >> hs;
        horses.insert(hs);
    }

    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vvi marian_dist = dijkstra(1);
    vvi robin_dist = dijkstra(n);

    int ans = 1e18;
    int res;

    for (int i = 1; i <= n; ++i)
    {
        for (int ms : {0, 1})
        {
            for (int rs : {0, 1})
            {
                res = max(marian_dist[i][ms], robin_dist[i][rs]);
                ans = min(ans, res);
            }
        }
    }

    if (ans == 1e18)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
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
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}