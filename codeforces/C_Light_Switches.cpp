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
void solve()
{
    cin >> n >> k;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    sortall(a);
    int maxi = a[n - 1];
    int x, y;

    int newMini = maxi;
    int newMaxi = maxi;
    loop(i, 0, n - 1)
    {
        x = maxi - a[i];
        y = x / k;

        if (y % 2)
        {
            if (abs(a[i] + k * (y + 1) - maxi) < k)
                y++;
            else
                y--;
        }

        // deb2(i, y);
        // deb2(x, y * k);

        newMini = min(newMini, a[i] + y * k);
        newMaxi = max(newMaxi, a[i] + y * k);
        // deb2(newMini, newMaxi);
    }

    if (abs(newMaxi - newMini) >= k)
        cout << -1 << nL;
    else
        cout << newMaxi << nL;
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