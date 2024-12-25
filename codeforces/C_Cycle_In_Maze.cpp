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
int n, m, k;
string dir = "DLRU";
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
int stx, sty;
void solve()
{
    cin >> n >> m >> k;
    vvi a(n, vi(m, 0));
    vvi vis(n, vi(m, 0));
    vvi dis(n, vi(m, 0));
    loop(i, 0, n)
    {
        string s;
        cin >> s;
        loop(j, 0, m)
        {
            if (s[j] == '*')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }

            if (s[j] == 'X')
            {
                stx = i;
                sty = j;
            }
        }
    }
    bool ch = false;
    loop(i, 0, 4)
    {
        int x = stx + dx[i];
        int y = sty + dy[i];
        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0)
        {
            ch = true;
        }
    }

    if (!ch || k % 2)
    {
        cout << "IMPOSSIBLE" << nL;
        return;
    }

    queue<pii> q;
    q.push(mk(stx, sty));
    vis[stx][sty] = 1;
    dis[stx][sty] = 0;

    while (!q.empty())
    {
        pii p = q.front();
        q.pop();
        loop(i, 0, 4)
        {
            int x = p.F + dx[i];
            int y = p.S + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0 && !vis[x][y])
            {
                vis[x][y] = 1;
                dis[x][y] = dis[p.F][p.S] + 1;
                q.push(mk(x, y));
            }
        }
    }

    int x = stx, y = sty;
    while (k)
    {
        loop(i, 0, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0 && dis[nx][ny] <= k - 1)
            {

                x = nx;
                y = ny;
                k--;
                cout << dir[i];
                break;
            }
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