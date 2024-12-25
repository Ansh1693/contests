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
    vi a(n);
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    int totMax = -1;
    vector<int> op;

    loop(i, 0, n)
    {
        totMax = max(totMax, a[i]);
    }

    while (totMax != 0 && op.size() <= 40)
    {
        totMax = 0;
        int mini = 1e9;
        int maxi = 0;
        loop(i, 0, n)
        {
            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);
        }

        int x = (mini + maxi) / 2;

        loop(i, 0, n)
        {
            a[i] = abs(a[i] - x);
            totMax = max(totMax, a[i]);
        }

        op.push_back(x);
    }

    if (op.size() > 40)
    {
        cout << -1 << nL;
    }
    else
    {
        cout << op.size() << nL;
        for (auto x : op)
        {
            cout << x << " ";
        }
        cout << nL;
    }

    // cout << ans << nL;
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