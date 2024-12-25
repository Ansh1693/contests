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
int n;
vi adj[500005];

bool vis[500005];

void solve()
{
    memset(vis, false, sizeof(vis));
    cin >> n;

    loop(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<pii> q;

    int tot = 0;

    map<int, vi> mp;
    int maxi = 0;
    int maxxx = 0;

    q.push({1, 0});

    while (!q.empty())
    {
        pii p = q.front();
        q.pop();

        int node = p.F;
        int dist = p.S;
        vis[node] = true;
        if (adj[node].size() == 1)
        {
            mp[dist].pb(node);
            tot++;
            cout << node << " " << dist << nL;
            maxi = mp[dist].size() > mp[maxi].size() ? dist : maxi;

            maxxx = max(maxxx, dist);
        }
        for (auto child : adj[node])
        {
            if (vis[child])
                continue;
            q.push({child, dist + 1});
        }
    }

    if (tot == mp[maxi].size())
    {
        cout << 0 << nL;
        return;
    }

    int res = INT_MAX;

    loop(i, 1, maxxx + 1)
    {
        int ans = 0;
        map<pii, bool> mpp;
        for (auto x : mp)
        {
            if (x.F == i)
                continue;

            int dist = x.F;
            if (dist < i)
            {
                for (auto node : x.S)
                {
                    int curr = node;
                    while (dist--)
                    {
                        if (adj[curr].size() == 1)
                        {
                            mpp[{min(curr, adj[curr][0]), max(curr, adj[curr][0])}] = true;
                            curr = adj[curr][0];
                            ans++;
                        }
                        else
                        {
                            int ch = 0;
                            int ind = 0;

                            for (auto child : adj[curr])
                            {
                                if (mpp[{min(curr, child), max(curr, child)}])
                                {
                                    continue;
                                }
                                else
                                {
                                    ch++;
                                    ind = child;
                                }
                            }

                            if (ch == 1)
                            {
                                mpp[{min(curr, ind), max(curr, ind)}] = true;
                                ans++;
                                curr = ind;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                for (auto node : x.S)
                {
                    int curr = node;
                    while (dist > i)
                    {
                        if (adj[curr].size() == 1)
                        {
                            mpp[{min(curr, adj[curr][0]), max(curr, adj[curr][0])}] = true;
                            curr = adj[curr][0];
                            ans++;
                        }
                        else
                        {
                            int ch = 0;
                            int ind = 0;

                            for (auto child : adj[curr])
                            {
                                if (mpp[{min(curr, child), max(curr, child)}])
                                {
                                    continue;
                                }
                                else
                                {
                                    ch++;
                                    ind = child;
                                }
                            }

                            if (ch == 1)
                            {
                                mpp[{min(curr, ind), max(curr, ind)}] = true;
                                ans++;
                                curr = ind;
                            }
                            else
                            {
                                break;
                            }
                        }

                        dist--;
                    }
                }
            }
        }
        res = max(res, ans);
    }

    cout
        << res << nL;

    loop(i, 0, n)
    {
        adj[i].clear();
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