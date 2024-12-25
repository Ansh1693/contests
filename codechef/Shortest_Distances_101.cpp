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
const int mod = 1e9;
const int N = 500005;
int n, q;
int a[N];
void solve()
{
    std::cin >> n >> q;
    loop(i, 1, n + 1) cin >> a[i];

    vector<umii> dist(n + 1);

    loop(i, 1, n + 1) dist[i][i] = 0;

    loop(i, 1, n + 1)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            if (i + j > n)
                break;
            if (dist[i].find(i + j) == dist[i].end())
                dist[i][i + j] = 1;
            else
                dist[i][i + j] = min(dist[i][i + j], 1LL);
            for (int k = 1; k <= n; k++)
            {
                if (dist[k].find(i) == dist[k].end())
                    continue;

                if (dist[k].find(i + j) == dist[k].end())
                    dist[k][i + j] = dist[k][i] + 1;
                else
                    dist[k][i + j] = min(dist[k][i + j], dist[k][i] + 1);
            }
        }
    }

    loop(i, 0, q)
    {
        int x, y;
        cin >> x >> y;
        if (dist[x].find(y) == dist[x].end())
        {
            cout << -1 << nL;
        }
        else
        {
            cout << dist[x][y] << nL;
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
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}