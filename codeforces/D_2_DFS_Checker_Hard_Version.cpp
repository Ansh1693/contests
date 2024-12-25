// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, q;
//         cin >> n >> q;

//         vector<int> a(n, -1);
//         for (int i = 1; i < n; i++)
//         {
//             cin >> a[i];
//             a[i]--;
//         }

//         vector<int> p(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> p[i];
//             p[i]--;
//         }

//         vector<int> pos(n);
//         for (int i = 0; i < n; i++)
//         {
//             pos[p[i]] = i;
//         }

//         int good = 0;
//         vector<set<int>> s(n);
//         vector<int> f(n);
//         vector<vector<int>> adj(n);

//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (i > 0)
//             {
//                 adj[a[i]].emplace_back(i);
//             }
//             for (int j : adj[i])
//             {
//                 f[i] += f[j];
//             }
//             f[i]++;
//         }

//         int bad = 0;

//         auto calc = [&](int i) -> bool
//         {
//             if (s[i].empty())
//                 return false;
//             int x = pos[i];
//             int y = *s[i].begin();
//             return y < x;
//         };

//         auto del = [&](int i, int x)
//         {
//             auto it = s[i].find(x);
//             int l = -1, r = -1;
//             if (it != s[i].begin())
//             {
//                 l = *prev(it);
//                 if (l + f[p[l]] != x)
//                     bad--;
//             }
//             if (next(it) != s[i].end())
//             {
//                 r = *next(it);
//                 if (x + f[p[x]] != r)
//                     bad--;
//             }
//             if (l != -1 && r != -1)
//             {
//                 if (l + f[p[l]] != r)
//                     bad++;
//             }
//             s[i].erase(it);
//         };

//         auto add = [&](int i, int x)
//         {
//             s[i].emplace(x);
//             auto it = s[i].find(x);
//             int l = -1, r = -1;
//             if (it != s[i].begin())
//             {
//                 l = *prev(it);
//                 if (l + f[p[l]] != x)
//                     bad++;
//             }
//             if (next(it) != s[i].end())
//             {
//                 r = *next(it);
//                 if (x + f[p[x]] != r)
//                     bad++;
//             }
//             if (l != -1 && r != -1)
//             {
//                 if (l + f[p[l]] != r)
//                     bad--;
//             }
//         };

//         for (int i = 0; i < n; i++)
//         {
//             if (a[p[i]] != -1)
//                 add(a[p[i]], i);
//         }

//         for (int i = 0; i < n; i++)
//         {
//             bad += calc(i);
//         }

//         while (q--)
//         {
//             int x, y;
//             cin >> x >> y;
//             x--, y--;
//             set<int> change;
//             change.emplace(p[x]);
//             change.emplace(p[y]);
//             change.emplace(a[p[x]]);
//             change.emplace(a[p[y]]);

//             for (int z : change)
//             {
//                 if (z != -1)
//                     bad -= calc(z);
//             }

//             if (a[p[x]] != -1)
//                 del(a[p[x]], x);
//             if (a[p[y]] != -1)
//                 del(a[p[y]], y);

//             swap(p[x], p[y]);
//             swap(pos[p[x]], pos[p[y]]);

//             if (a[p[x]] != -1)
//                 add(a[p[x]], x);
//             if (a[p[y]] != -1)
//                 add(a[p[y]], y);

//             for (int z : change)
//             {
//                 if (z != -1)
//                     bad += calc(z);
//             }

//             cout << (bad == 0 ? "YES\n" : "NO\n");
//         }
//     }
//     return 0;
// }

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
const int N = 3e5;
int par[N];
int a[N];
vi adj[N];
int pos[N];
int f[N];
int n, q;
int q_1, q_2;

void solve()
{
    cin >> n >> q;
    loop(i, 1, n)
    {
        cin >> par[i];
        par[i]--;
    }
    loop(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        pos[a[i]] = i;
    }

    loop(i, 0, n)
    {
        adj[i].clear();
        f[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i > 0)
        {
            adj[par[i]].pb(i);
        }
        f[i]++;
        for (int j : adj[i])
        {
            f[i] += f[j];
        }
    }

    loop(i, 0, q)
    {
        cin >> q_1 >> q_2;
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