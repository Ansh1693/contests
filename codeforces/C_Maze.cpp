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
int vis[1000][1000];
string a[1000];
int cntk;
void dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || cntk == 0)
    {
        return;
    }
    vis[i][j] = 1;
    cntk--;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

void solve()
{
    cin >> n >> m >> k;
    int cnt = 0;
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            vis[i][j] = a[i][j] == '.' ? 0 : 1;
            cnt += a[i][j] == '.';
        }
    }

    cntk = cnt - k;

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
            }
        }
    }

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            if (vis[i][j])
                cout << a[i][j];
            else
                cout << "X";
        }
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