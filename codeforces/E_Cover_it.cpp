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
vi adj[200005];
int col[200005];

void dfs(int n, int c)
{
    col[n] = c;
    for (auto i : adj[n])
    {
        if (col[i] == -1)
        {
            dfs(i, c ^ 1);
        }
    }
}

void solve()
{
    cin >> n >> m;
    loop(i, 0, n)
    {
        adj[i].clear();
    }
    loop(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    loop(i, 0, n)
    {
        col[i] = -1;
    }
    int ones = 0;
    loop(i, 0, n)
    {
        if (col[i] == -1)
        {
            dfs(i, 0);
        }

        ones += col[i];
    }

    if (ones > n - ones)
    {
        cout << n - ones << nL;
        loop(i, 0, n)
        {
            if (col[i] == 0)
            {
                cout << i + 1 << " ";
            }
        }
    }
    else
    {
        cout << ones << nL;
        loop(i, 0, n)
        {
            if (col[i] == 1)
            {
                cout << i + 1 << " ";
            }
        }
    }

    cout << nL;
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