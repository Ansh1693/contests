// https://atcoder.jp/contests/abc362/tasks/abc362_c

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
    vector<pii> a(n);
    int minSum = 0;
    int maxSum = 0;
    loop(i, 0, n)
    {
        cin >> a[i].F >> a[i].S;
        minSum += a[i].F;
        maxSum += a[i].S;
    }

    if (minSum > 0 || maxSum < 0)
    {
        cout << "No" << nL;
        return;
    }

    vector<int> res(n);

    int target = 0;

    loop(i, 0, n)
    {
        res[i] = a[i].F;
        target -= a[i].F;
    }

    for (int i = 0; i < n && target > 0; ++i)
    {
        int inc = min(target, a[i].S - a[i].F);
        res[i] += inc;
        target -= inc;
    }

    for (int i = 0; i < n && target < 0; ++i)
    {
        int dec = min(-target, a[i].F - a[i].S);
        res[i] -= dec;
        target += dec;
    }

    if (target == 0)
    {
        cout << "Yes" << nL;
        loop(i, 0, n)
        {
            cout << res[i] << " ";
        }
        cout << nL;
    }
    else
    {
        cout << "No" << nL;
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