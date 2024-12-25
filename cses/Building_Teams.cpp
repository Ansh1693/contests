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

void solve()
{
    cin >> n >> m;
    int a, b;
    loop(i, 0, m)
    {
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi color(n, -1);
    bool isBipartite = true;

    function<void(int, int)> dfs = [&](int node, int col)
    {
        color[node] = col;
        for (int i : adj[node])
        {
            if (color[i] == -1)
            {
                dfs(i, col ^ 1);
            }
            else
            {
                isBipartite &= color[i] != color[node];
            }
        }
    };

    loop(i, 0, n)
    {
        if (color[i] == -1)
        {
            dfs(i, 0);
        }
    }

    if (!isBipartite)
    {
        cout << "IMPOSSIBLE" << nL;
        return;
    }

    loop(i, 0, n)
    {
        cout << color[i] + 1 << " ";
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