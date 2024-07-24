// https://atcoder.jp/contests/abc362/tasks/abc362_d

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
    int n, m;
    cin >> n >> m;

    map<int, vector<pii>> mp;
    vi a(n + 1);
    loop(i, 1, n + 1)
    {
        cin >> a[i];
    }

    loop(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].pb({v, w});
        mp[v].pb({u, w});
    }

    vector<int> dist(n + 1, LLONG_MAX);
    dist[1] = a[1];

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({1, a[1]});

    while (!pq.empty())
    {
        pii curr = pq.top();
        pq.pop();

        int u = curr.F;

        if (curr.S > dist[u])
            continue;

        for (auto it : mp[u])
        {
            int v = it.F;
            int newDist = dist[u] + it.S + a[v];

            if (newDist < dist[v])
            {
                dist[v] = newDist;
                pq.push({v, newDist});
            }
        }
    }

    loop(i, 2, n + 1)
    {

        cout << dist[i] << " ";
    }
    cout << nL;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}