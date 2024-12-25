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

map<pii, int> mp;
map<pii, int> vis;
map<pii, int> dis;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve()
{
    int x_0, y_0, x_1, y_1;
    int n;
    cin >> x_0 >> y_0 >> x_1 >> y_1;
    dis[mk(x_1, y_1)] = -1;
    cin >> n;
    loop(i, 0, n)
    {
        int r, a, b;
        cin >> r >> a >> b;
        forEqual(j, a, b)
        {
            mp[mk(r, j)]++;
        }
    }

    queue<pii> q;
    q.push(mk(x_0, y_0));
    vis[mk(x_0, y_0)] = 1;
    // dis[mk(x_0, y_0)] = 0;

    while (!q.empty())
    {
        pii p = q.front();
        q.pop();
        loop(i, 0, 8)
        {
            int x = p.F + dx[i];
            int y = p.S + dy[i];
            if (mp[mk(x, y)] && !vis[mk(x, y)])
            {

                vis[mk(x, y)] = 1;
                dis[mk(x, y)] = dis[p] + 1;
                q.push(mk(x, y));
            }
        }
    }

    cout << dis[mk(x_1, y_1)] << nL;
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