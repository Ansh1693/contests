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
int adj[200005];
string s;
bool vis[200005];
int ans[200005];

void solve()
{
    cin >> n;
    loop(i, 1, n + 1) cin >> adj[i];
    cin >> s;
    s.insert(s.begin(), ' ');
    memset(vis, false, sizeof(vis));
    memset(ans, 0, sizeof(ans));

    loop(i, 1, n + 1)
    {
        if (!vis[i])
        {
            int cur = i;

            vi cy;
            int cnt = 0;

            while (!vis[cur])
            {
                vis[cur] = true;
                cy.pb(cur);
                cur = adj[cur];

                if (s[cur] == '0')
                {
                    cnt++;
                }
            }

            loop(j, 0, cy.size())
            {
                ans[cy[j]] = cnt;
            }
        }
    }

    forEqual(i, 1, n) cout << ans[i] << " ";
    cout << nL;
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