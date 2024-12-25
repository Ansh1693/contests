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
int pow2[200005];
vi a;

void solve()
{
    cin >> n >> k;
    if (k > pow2[n - 1])
    {
        cout << -1 << nL;
        return;
    }
    k--;

    loop(i, 1, n)
    {
        int val = pow2[n - i - 1];
        if (k >= val)
        {
            k -= val;
            a.pb(i);
        }
        else
        {
            cout << i << " ";
        }
    }

    cout << n << " ";
    rloop(i, 0, a.size())
    {
        cout << a[i] << " ";
    }

    cout << nL;

    a.clear();
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
    pow2[0] = 1LL;
    loop(i, 1, 200005)
    {
        pow2[i] = min(pow2[i - 1] * 2LL, (int)1e18);
    }
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}