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
int n, k;
int a[200005];

bool good(int diff)
{
    int ch = 0;
    int low = a[0] - diff;
    int high = a[0] + diff;

    loop(i, 1, n)
    {
        if (high < a[i] - diff || low > a[i] + diff)
        {
            ch++;
            low = a[i] - diff;
            high = a[i] + diff;
        }
        else
        {
            low = max(low, a[i] - diff);
            high = min(high, a[i] + diff);
        }
    }

    return ch <= k;
}

void solve()
{
    cin >> n >> k;
    int devi = 0;
    loop(i, 0, n)
    {
        cin >> a[i];
        if (i > 0)
        {
            if (a[i] != a[i - 1])
                devi++;
        }
    }

    if (devi <= k)
    {
        cout << 0 << nL;
        return;
    }

    int l = 0, r = 1e9, ans = 1e9;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (good(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
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
    //  #endif
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}