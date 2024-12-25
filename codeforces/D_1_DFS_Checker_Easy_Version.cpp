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
const int N = 65536;
int n, q, q_1, q_2;
int p[N];
int a[N];
si adj[N];
si adj2[N];

void makeAdj()
{
    for (int i = n - 1; i >= 1; i--)
    {
        adj[p[i]].insert(i);
        adj[p[i]].insert(adj[i].begin(), adj[i].end());
    }
}

bool makeNew()
{
    loop(i, 0, n)
    {
        adj2[i].clear();
    }

    for (int i = n - 1; i >= 1; i--)
    {
        adj2[a[p[i]]].insert(adj2[a[i]].begin(), adj2[a[i]].end());
        adj2[a[p[i]]].insert(a[i]);
    }

    loop(i, 0, n)
    {

        if (adj[i] != adj2[i])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n >> q;
    loop(i, 1, n)
    {
        cin >> p[i];
        p[i]--;
    }

    loop(i, 0, n) cin >> a[i], a[i]--, adj[i].clear();

    for (int i = n - 1; i >= 1; i--)
    {
        adj[p[i]].insert(i);
        adj[p[i]].insert(adj[i].begin(), adj[i].end());
    }

    loop(i, 0, q)
    {
        cin >> q_1 >> q_2;
        q_1--;
        q_2--;
        swap(a[q_1], a[q_2]);

        if (makeNew())
        {
            cout << "YES" << nL;
        }
        else
        {
            cout << "NO" << nL;
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