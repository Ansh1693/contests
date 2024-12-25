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
int k;
int vis[2005][2005];
int dist[2005][2005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void solve()
{
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            dist[i][j] = 1e9;
        }
    }
    cin >> k;
    queue<pair<pii, int>> q;
    loop(i, 0, k)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        q.push({{x, y}, 0});
    }

    int maxi = -1;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.F.F;
        int y = p.F.S;
        int d = p.S;
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        dist[x][y] = min(dist[x][y], d);

        maxi = max(maxi, d);
        loop(i, 0, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                q.push({{nx, ny}, d + 1});
            }
        }
    }

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            if (dist[i][j] == maxi)
            {
                cout << i + 1 << " " << j + 1 << nL;
                return;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}