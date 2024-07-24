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
    int n, k;
    cin >> n >> k;

    vi a(n);
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    int ans = 0;

    int newSum = 0;

    bool ch = false;

    loop(i, 1, n)
    {
        ans += abs(a[i] - a[i - 1]);
    }

    // cout << ans << endl;

    int prev, one, kone;
    loop(i, 0, n)
    {
        if (i == 0)
        {
            prev = abs(a[i] - a[i + 1]);
            one = abs(1 - a[i + 1]);
            kone = abs(k - a[i + 1]);

            newSum = max(newSum, ans + one - prev);
            newSum = max(newSum, ans + kone - prev);
        }
        else if (i == n - 1)
        {
            prev = abs(a[i] - a[i - 1]);
            one = abs(1 - a[i - 1]);
            kone = abs(k - a[i - 1]);

            newSum = max(newSum, ans + one - prev);
            newSum = max(newSum, ans + kone - prev);
        }
        else
        {
            prev = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
            one = abs(1 - a[i - 1]) + abs(1 - a[i + 1]);
            kone = abs(k - a[i - 1]) + abs(k - a[i + 1]);

            newSum = max(newSum, ans + one - prev);
            newSum = max(newSum, ans + kone - prev);
        }

        // cout << a[i] << " " << newSum << " prev:" << prev << " one:" << one << " kone:" << kone << nL;
    }

    cout << newSum << nL;
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