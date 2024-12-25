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
int a[50];
int n, k;
int start;

vi ans;

void solve()
{
    cin >> n >> k;
    vector<pii> b;
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    loop(i, 0, n)
    {
        if (a[i] == k)
        {
            cout << "YES" << nL;
            cout << 1 << nL;
            cout << i + 1 << nL;
            return;
        }

        // cout << a[i] << " " << k << " " << (a[i] & k) << nL;

        if ((a[i] & k) == k)
        {
            b.push_back({a[i], i});
        }
    }

    vi ans;
    n = b.size();

    // for (auto it : b)
    // {
    //     cout << it.F << " " << it.S << nL;
    // }

    loop(i, 0, (1 << n))
    {
        int curr = start;
        ans.clear();

        loop(j, 0, n)
        {
            if (i & (1 << j))
            {
                curr &= b[j].F;
                ans.pb(b[j].S + 1);
            }
        }

        if (curr == k)
        {
            cout << "YES" << nL;
            cout << ans.size() << nL;
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << nL;
            return;
        }
    }

    cout << "NO" << nL;
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
    cin >> tc;
    start = (1 << 30) - 1;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}