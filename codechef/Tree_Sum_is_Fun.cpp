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

int u, n;

int good(int st)
{
    int sm = 0;
    int steps = 0;

    while (st > 0 && steps < n)
    {
        sm += st;
        st /= 2;
        steps++;
    }

    if (sm == u && steps <= n)
    {
        return 0;
    }
    else if (sm < u)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void solve()
{
    cin >> u >> n;
    int l = 1, r = u;
    bool ch = 0;
    int mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        int res = good(mid);

        if (res == 0)
        {
            ch = 1;
            break;
        }
        else if (res == 1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    if (!ch)
    {
        cout << -1 << nL;
    }
    else
    {
        cout << mid << nL;
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
