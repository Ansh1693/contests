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
int a[50];

bool good(int coins)
{
    int sum = 0;
    loop(i, 0, n)
    {
        if (sum + a[i] + coins > k)
        {
            sum += a[i];
            if (sum < k && coins > 0)
            {
                sum = k;
            }
        }
        else
        {
            sum += a[i] + coins;
            coins = 0;
        }

        if (sum >= k)
            break;
    }

    return sum == k;
}

void solve()
{
    cin >> n >> k;
    loop(i, 0, n) cin >> a[i];

    sort(a, a + n, greater<int>());

    int l = 0, r = 1e9;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (good(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l << nL;
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