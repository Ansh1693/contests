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
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void solve()
{
    int n;
    set<pii> mp;
    map<pii, pii> ans;
    cin >> n;
    vector<pii> v(n);
    loop(i, 0, n)
    {
        cin >> v[i].F >> v[i].S;
        mp.insert(v[i]);
    }

    queue<pii> q;

    loop(i, 0, n)
    {
        loop(j, 0, 4)
        {
            int nx = v[i].F + dx[j];
            int ny = v[i].S + dy[j];
            if (mp.count(mk(nx, ny)))
                continue;
            ans[v[i]] = mk(nx, ny);
            q.push(v[i]);
            break;
        }
    }

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();
        loop(i, 0, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!mp.count(mk(nx, ny)) || ans.count(mk(nx, ny)))
            {
                continue;
            }
            ans[mk(nx, ny)] = ans[{x, y}];
            q.push(mk(nx, ny));
        }

        // cout << p.F << " " << p.S << " " << ans[{2, 2}].F << " " << ans[{2, 2}].S << nL;
    }

    for (auto i : v)
    {
        auto it = ans[i];
        cout << it.F << " " << it.S << nL;
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