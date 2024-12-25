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
string s[1002];
vector<pii> adj[1002][1002];

void solve()
{
    cin >> n >> m;
    loop(i, 1, n + 1)
    {
        cin >> s[i];
        s[i] = "." + s[i];
    }

    loop(i, 1, n + 1)
    {
        loop(j, 1, m + 1)
        {
            if (s[i][j] == 'U')
            {
                adj[i - 1][j].pb({i, j});
            }

            if (s[i][j] == 'D')
            {
                adj[i + 1][j].pb({i, j});
            }

            if (s[i][j] == 'L')
            {
                adj[i][j - 1].pb({i, j});
            }

            if (s[i][j] == 'R')
            {
                adj[i][j + 1].pb({i, j});
            }
        }
    }
    vvi vis(n + 2, vi(m + 2, 0));
    queue<pii> q;
    int cnt = 0;

    loop(j, 1, m + 1)
    {

        q.push({0, j});
        vis[0][j] = 1;
    }

    loop(j, 1, m + 1)
    {

        q.push({n + 1, j});
        vis[n + 1][j] = 1;
    }

    loop(i, 1, n + 1)
    {

        q.push({i, 0});
        vis[i][0] = 1;
    }

    loop(i, 1, n + 1)
    {
        q.push({i, m + 1});
        vis[i][m + 1] = 1;
    }

    while (!q.empty())
    {
        pii p = q.front();
        q.pop();
        for (auto x : adj[p.F][p.S])
        {
            if (!vis[x.F][x.S])
            {
                vis[x.F][x.S] = 1;
                q.push(x);
                if (x.F > 0 && x.F <= n && x.S > 0 && x.S <= m)
                    cnt++;
            }
        }
    }

    loop(i, 1, n + 1)
    {
        loop(j, 1, m + 1)
        {
            if (s[i][j] == '?' && vis[i - 1][j] && vis[i + 1][j] && vis[i][j - 1] && vis[i][j + 1])
            {
                vis[i][j] = 1;
                cnt++;
            }
        }
    }

    cout << n * m - cnt << nL;

    loop(i, 0, n + 2)
    {
        loop(j, 0, m + 2)
        {
            adj[i][j].clear();
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    //  #endif
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}