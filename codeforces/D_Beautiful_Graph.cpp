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
const int mod = 998244353;
const int N = 3e5 + 7;
int n, m;

int p2[N];
int cnt[2];
int col[N];
vi adj[N];
bool ch;

void dfs(int n, int c)
{
    col[n] = c;
    cnt[c]++;
    for (int x : adj[n])
    {
        if (col[x] == -1)
        {
            dfs(x, c ^ 1);
        }

        if (col[x] ^ col[n] == 0)
            ch = 0;
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
    int ans = 1;
    loop(i, 0, n)
    {
        col[i] = -1;
    }

    loop(i, 0, n)
    {
        if (col[i] == -1)
        {
            cnt[0] = cnt[1] = 0;
            ch = 1;
            dfs(i, 0);
            if (ch)
            {
                int res = (p2[cnt[0]] + p2[cnt[1]]) % mod;
                ans = (ans * 1LL * res) % mod;
            }
            else
            {
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << ans << endl;
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
    p2[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        p2[i - 1] = p2[i - 1] % mod;
        p2[i] = (2 * p2[i - 1]) % mod;
        p2[i] = p2[i] % mod;
    }
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}