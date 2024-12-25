#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
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
const int mod = 998244353;
int n;
int g, w;
int l;

int mod_exp(int x, int y, int mod)
{
    int result = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

int mod_inverse(int a, int mod)
{
    return mod_exp(a, mod - 2, mod);
}

void solve()
{
    cin >> w >> g >> l;
    if (l == 0)
    {
        cout << (w - g) % mod << nL;
    }
    else
    {
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    cin >> tc;
    cout << setprecision(20) << fixed;

    for (int t = 1; t <= tc; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}