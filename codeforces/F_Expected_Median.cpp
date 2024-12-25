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

vector<int> fact;

const int N = 2e5 + 5;
int pw(int a, int b)
{
    int r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = (r * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return r;
}
int C(int n, int k)
{
    if (n < k)
        return 0LL;
    return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int x;
    int ones = 0;
    loop(i, 0, n) cin >> x, ones += x;
    int z = n - ones;
    int ans = 0;
    int mid = k / 2;
    mid++;
    if (ones < mid)
    {
        cout << 0 << nL;
        return;
    }

    for (int i = min(k, ones); i >= mid; i--)
    {
        if (k - i <= z)
        {

            ans += C(ones, i) * C(z, k - i) % mod;
            ans %= mod;
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
    // #endif
    fact.resize(N, 1);
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
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