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
int a[200005], b[200005];

void solve()
{
    cin >> n >> k;
    loop(i, 0, n)
    {
        cin >> b[i];
        a[i] = gcd(b[i], k);
    }

    bool ch = true;
    loop(i, 0, n)
    {
        if (b[i] != k)
        {
            ch = false;
            break;
        }
    }

    if (ch)
    {
        cout << 0 << nL;
        return;
    }

    int l = INT_MIN, r = n;

    loop(i, 0, n)
    {
        if (b[i] != k)
        {
            if (l == INT_MIN)
            {
                l = i;
            }
            r = i;
        }
    }

    if (r - l == 0)
    {
        cout << 1 << nL;
        return;
    }

    bool ch1 = 1, ch2 = 1;
    loop(i, l, r + 1)
    {
        if (b[i] % k != 0)
            ch1 = 0;

        if ((b[i] ^ k) != (b[l] ^ k))
            ch2 = 0;
    }

    if (ch1 || ch2)
    {
        cout << 1 << nL;
        return;
    }

    cout << 2 << nL;
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