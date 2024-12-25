#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nL "\n"
#define pb push_back
#define F first
#define S second
#define forEqual(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b - 1; i >= a; i--)
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

class Node
{
public:
    int v, c, t;

    Node(int v, int c, int t)
    {
        this->v = v;
        this->c = c;
        this->t = t;
    }

    bool operator>(const Node &other) const
    {
        if (c == other.c)
            return t > other.t;
        return c < other.c;
    }
};

vector<char> segmentedSieveNoPreGen(int R)
{
    int L = 0;
    vector<char> isPrime(R - L + 1, true);
    int lim = sqrt(R);
    for (int i = 2; i <= lim; ++i)
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

void solve()
{
    int n, m, st, en;
    cin >> n >> m >> st >> en;
    int u, v, c, t;

    vector<vector<Node>> adj(n + 1);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    loop(i, 0, m)
    {
        cin >> u >> v >> c >> t;
        adj[u].pb(Node(v, c, t));
    }
    vector<char> primes = segmentedSieveNoPreGen(5e6 + 5);

    vector<pii> dist(n + 1, {LLONG_MAX, 0});

    pq.push(Node(st, LLONG_MAX, 0));

    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        for (Node &neigh : adj[curr.v])
        {
            int newCap = min(curr.c, neigh.c);
            int newCost = curr.t + neigh.t;

            while (!primes[newCap])
            {
                newCap--;
            }

            if (newCap < dist[neigh.v].S)
            {
                continue;
            }

            if (newCap == dist[neigh.v].S && newCost >= dist[neigh.v].F)
            {
                continue;
            }

            dist[neigh.v] = {newCost, newCap};
            pq.push(Node(neigh.v, newCap, newCost));
        }
    }

    if (dist[en].F == LLONG_MAX)
    {
        cout << "0 0" << nL;
    }
    else
    {
        if (dist[en].S == 1)
        {
            cout << dist[en].S << " " << dist[en].F * dist[en].S << nL;
        }
        else
        {

            int ind = dist[en].S;
            cout << ind << " " << dist[en].F * ind << nL;
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