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
set<pii> ans;
int vis[1001];

void bfs(int x, int y)
{
    cout << "? " << min(x, y) << " " << max(y, x) << endl;

    cout.flush();
    int z;
    cin >> z;

    if (z == -1)
        exit(0);
    if (z == x || z == y)
    {
        vis[x] = vis[y] = 1;
        ans.insert({min(x, y), max(x, y)});
    }
    else
    {
        cout << "? " << max(x, y) << " " << min(x, y) << endl;
        int z1;
        cin >> z1;
        cout.flush();
        if (z1 == -1)
            exit(0);
        if (z1 == z)
        {
            vis[x] = vis[y] = 1;
            vis[z] = 1;
            ans.insert({min(x, z), max(x, z)});
            ans.insert({min(y, z), max(y, z)});
        }
        else
        {
            bfs(z, z1);
            ans.insert({min(x, z), max(x, z)});
            ans.insert({min(y, z1), max(y, z1)});
        }
    }
}

void solve()
{
    ans.clear();
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans.size() == n - 1)
                break;
            if (i == j || ans.count({min(i, j), max(i, j)}) || (vis[i] && vis[j]))
                continue;

            bfs(i, j);
        }

        if (ans.size() == n - 1)
            break;
    }

    cout << "! ";
    for (auto x : ans)
        cout << x.F << " " << x.S << " ";

    cout << endl;
    cout.flush();
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