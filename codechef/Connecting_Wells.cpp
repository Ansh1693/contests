
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
    vector<pii> wells(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> wells[i].first >> wells[i].second;
    }

    vector<vector<pii>> adj(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int x = abs(wells[i].first - wells[j].first);
            int y = abs(wells[i].second - wells[j].second);
            int weight = (x == 0) ? (y / 2 + (y % 2)) : (y == 0) ? (x / 2 + (x % 2))
                                                                 : max(x, y);
            adj[i].emplace_back(j, weight);
            adj[j].emplace_back(i, weight);
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n, 1e18);
    vector<bool> visited(n, false);

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (const auto &[v, weight] : adj[u])
        {
            if (!visited[v] && weight < dist[v])
            {
                dist[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    int max_distance = 0;
    loop(i, 0, n)
    {
        max_distance = max(max_distance, dist[i]);
    }

    cout << max_distance << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}
