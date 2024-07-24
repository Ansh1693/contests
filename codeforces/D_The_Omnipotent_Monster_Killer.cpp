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

void dfs(int v, int c, vector<bool> &vis,vi &color, int& 1sum) {
    color[v] = c;
    vis[v] = true;
    if (c == 0) {
        set1sum += attack[v];
    } else {
        set2sum += attack[v];
    }
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, 1 - c);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vi a(n+1);
    
    loop(i,1,n+1){
        cin >> a[i];
    }

    int set1sum = 0;
    int set2sum = 0;

    vvi adj(n+1);
 
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    vector<bool> vis(n+1,false);

    vi color(n+1);
 
    dfs(1, 0); 
 
    int ans = max(set1sum, set2sum) +min(set1sum, set2sum) * 2;

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