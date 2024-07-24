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

void print(vi &a)
{
    cout << a.size() - 1 << nL;
    loop(i, 1, a.size())
    {
        cout << a[i] + 1 << " ";
    }

    cout << nL;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> value(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int mini = min_element(value.begin(), value.end()) - value.begin();

    vector<bool> vis(n, false);
    deque<int> bfs;
    vector<int> ans;

    ans.push_back(mini);
    vis[mini] = true;
    bfs.push_back(mini);

    while (!bfs.empty())
    {
        int nd = bfs.front();
        bfs.pop_front();

        for (int it : adj[nd])
        {
            if (!vis[it])
            {
                vis[it] = true;
                ans.push_back(it);
                bfs.push_back(it);
            }
        }
    }

    reverse(ans.begin() + 1, ans.end());
    print(ans);
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