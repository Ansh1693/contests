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
    int n, k, h;
    cin >> n >> k >> h;

    int t = h / k;

    int t1 = h - (k * t);

    if (t1 != 0)
    {
        t++;
    }
    int a = t;
    int rem = h - ((t - 1) * (k - 1));
    int ans = ((n - t) * (n - t + 1)) / 2;

    for (int i = rem; i < n + 1; i++)
    {
        a = a - 1;
        int b = k - 1;

        while (a > 0)
        {
            int rem2 = a * b;
            rem2 = h - rem2;
            if (rem2 > i + a)
            {
                break;
            }
            else
            {
                a--;
            }
        }

        a++;

        ans += t - a;
    }

    if (n >= h)
    {
        int diff = n - h + 1;
        ans += diff * (diff + 1) / 2;
    }
    cout << ans << nL;
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