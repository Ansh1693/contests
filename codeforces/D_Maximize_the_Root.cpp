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

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    loop(i, 0, n)
    {
        cin >> a[i + 1];
    }

    vi adj(n + 1, 0);
    vi par(n + 1, -1);
    int ans = 1e9;
    loop(i, 1, n)
    {
        cin >> par[i + 1];
        adj[par[i + 1]]++;
    }

    int x = 2;
    while (x < n)
    {
        if (adj[x] == 0)
        {
            int vertice = x;
            int avg = a[vertice];
            while (par[vertice] != 1)
            {
                // cout << v << " " << avg << " " << a[v] << " " << a[par[v]] << nL;
                vertice = par[vertice];
                if (a[vertice] < avg)
                {
                    avg = (avg + a[vertice]) / 2;
                }
            }

            ans = max(ans, avg);
        }

        x++;
    }

    if (ans == 1e9)
    {
        cout << a[1] << nL;
        return;
    }

    cout << ans + a[1] << nL;
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