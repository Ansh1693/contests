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
vi adj[2501];

void solve()
{
    cin >> n >> m;
    loop(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 1e9;

    loop(i, 0, n)
    {
        queue<int> q;
        vi dist(n, -1);
        q.push(i);
        dist[i] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto x : adj[node])
            {
                if (dist[x] == -1)
                {
                    dist[x] = dist[node] + 1;
                    q.push(x);
                }
                else if (dist[x] >= dist[node])
                {
                    ans = min(ans, dist[x] + dist[node] + 1);
                }
            }
        }
    }

    if (ans == 1e9)
        ans = -1;

    cout << ans << nL;

    // loop(i, 0, n)
    // {
    //     cout << i + 1 << ": ";
    //     for (auto x : adj[i])
    //     {
    //         cout << x + 1 << " ";
    //     }
    //     cout << nL;
    // }
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