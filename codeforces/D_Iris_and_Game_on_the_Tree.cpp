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

vi adj[100005];
int n;
bool vis[100005];
string s2, s1;
int turn = 0;
int weight[100005];

void dfs(int cnt01, int cnt10, int node, int parent, string &s)
{
    vis[node] = true;
    if (s[node] == '?')
    {
        if (turn == 1)
        {
            turn = 0;
            if (cnt10 == cnt01)
            {
                s[node] = s[parent];
            }
            else if (cnt10 > cnt01)
            {
                s[node] = '1';
                if (s[parent] == '0')
                    cnt01++;
            }
            else
            {
                s[node] = '0';
                if (s[parent] == '1')
                    cnt10++;
            }
        }
        else
        {
            turn = 1;
            if (cnt10 == cnt01)
            {
                if (s[parent] == '0')
                    s[node] = '1', cnt01++;
                else
                    s[node] = '0', cnt10++;
            }
            else if (cnt10 > cnt01)
            {
                s[node] = '0';
                if (s[parent] == '1')
                    cnt10++;
            }
            else
            {
                s[node] = '1';
                if (s[parent] == '0')
                    cnt01++;
            }
        }
    }
    else if (s[node] == '0')
    {
        if (s[parent] == '1')
        {
            cnt10++;
        }
    }
    else
    {
        if (s[parent] == '0')
        {
            cnt01++;
        }
    }

    weight[node] = cnt01 - cnt10;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(cnt01, cnt10, it, node, s);
        }
    }
}

void solve()
{
    cin >> n;
    memset(vis, false, sizeof(vis));
    loop(i, 0, n)
    {
        adj[i].clear();
    }

    loop(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> s2;
    s1 = s2;
    if (s2[0] == '?')
    {
        turn = 1;
        s2[0] = '0';
    }

    vis[0] = true;

    for (auto it : adj[0])
    {
        dfs(0, 0, it, 0, s2);
    }

    int ans = 0;

    weight[0] = 0;

    loop(i, 0, n)
    {
        if (weight[i] != 0)
        {
            ans++;
        }
    }

    if (s1[0] == '?')
    {
        memset(vis, false, sizeof(vis));

        turn = 1;
        s1[0] = '1';

        vis[0] = true;

        for (auto it : adj[0])
        {
            dfs(0, 0, it, 0, s1);
        }

        int ans1 = 0;

        weight[0] = 0;

        loop(i, 0, n)
        {
            if (weight[i] != 0)
            {
                ans1++;
            }
        }

        ans = min(ans, ans1);
    }

    cout << ans << nL;
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