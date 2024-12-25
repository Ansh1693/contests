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
map<pii, int> mp;
vector<int> adj[200005];

void solve()
{

    cin >> n;
    int node = 1;
    loop(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[mk(min(u, v), max(u, v))] = i;

        node = adj[node].size() < adj[u].size() ? u : node;
        node = adj[node].size() < adj[v].size() ? v : node;
    }

    vector<int> ans[adj[node].size() + 1];
    queue<int> q;
    q.push(node);
    vi last(n + 1, -1);
    last[node] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int cnt = 1;
        for (int v : adj[u])
        {
            if (last[v] == -1)
            {
                if (last[u] == cnt)
                    cnt++;
                ans[cnt].pb(mp[mk(min(u, v), max(u, v))]);
                last[v] = cnt;
                cnt++;
                q.push(v);
            }
        }
    }
    cout << adj[node].size() << nL;
    for (int i = 1; i <= adj[node].size(); i++)
    {
        cout << ans[i].size() << " ";
        for (int x : ans[i])
            cout << x << " ";
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