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
int a[200005] = {0};
int calc[200005] = {0};
int x, y;
void solve()
{
    cin >> n;
    memset(a, 0, sizeof(a));
    a[0] = n;
    int ans = calc[n];
    int maxi = -1;
    loop(i, 0, n)
    {
        cin >> x >> y;

        if (maxi == -1)
            maxi = y;
        ans -= calc[a[maxi] + a[0]];

        a[y]++;
        a[0]--;

        if (a[y] > a[maxi])
            maxi = y;

        ans += calc[a[maxi] + a[0]];

        if (y != maxi)
        {
            ans -= calc[a[y] - 1];
            ans += calc[a[y]];
        }

        cout << ans << " ";
    }

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

    calc[2] = 1;
    forEqual(i, 3, 200000)
    {
        calc[i] = calc[i - 1] + i - 1;
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}