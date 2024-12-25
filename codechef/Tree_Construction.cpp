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
    int n, d, l;
    cin >> n >> d >> l;

    if (n == 2)
    {
        if (d == 1)
        {

            cout << 1 << " " << 2 << nL;
            return;
        }
        cout << -1 << nL;
        return;
    }

    if (d == 1)
    {
        cout << -1 << nL;
        return;
    }

    int maxleaves = n - (d + 1) + 2;
    int dd = d / 2;
    int nn = n - 1;

    int minLeaves = nn / dd + (nn % dd != 0);
    minLeaves -= (d % 2 == 1);
    // cout << maxleaves << " " << minLeaves << nL;
    if (l > maxleaves || l < minLeaves)
    {
        cout << -1 << nL;
        return;
    }
    // cout << "start" << nL;
    int i = 1;
    while (i <= dd)
    {

        cout << i << " " << i + 1 << nL;

        i++;
    }
    if (d % 2)
    {
        cout << i << " " << i + 1 << nL;
        i++;
    }
    i++;
    l--;
    int rem = n - dd - 1;
    rem -= (d % 2);
    // cout << rem << nL;
    while (i <= n)
    {
        cout << 1 << " " << i << nL;
        rem--;
        int pre = i;
        i++;
        int curr = 2;
        l--;
        while (i <= n && rem > l && curr <= dd)
        {
            cout << pre << " " << i << nL;
            rem--;
            pre = i;
            i++;
            curr++;
        }
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