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

int fact[2001];
int inv_fact[2001];
int inv_pow[2001];

int binpow(int a, int b)
{
    int res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1LL)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return res;
}
int n, m;

void solve()
{
    cin >> n >> m;
    n = min(2000LL, n);
    m = min(2000LL, m);

    int ans = 0;
    vi tot;
    loop(i, 1, m + 1)
    {
        if (i >= n)
        {
            int C = fact[i - 1] * inv_fact[n - 1] % mod;
            C = C * inv_fact[i - n] % mod;
            C = C * inv_pow[i] % mod;
            ans = (ans + C) % mod;
        }

        tot.pb(ans);
    }
    for (int i = 0; i < tot.size(); i++)
    {
        if (i > 0)
            cout << ' ';
        cout << tot[i];
    }
    cout << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    // #endif

    memset(fact, 1, sizeof(fact));
    for (int i = 1; i <= 2000; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    memset(inv_fact, 1, sizeof(inv_fact));
    inv_fact[2000] = binpow(fact[2000], mod - 2);
    for (int i = 1999; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
    memset(inv_pow, 1, sizeof(inv_pow));
    int inv2 = binpow(2, mod - 2);

    for (int i = 1; i <= 2000; i++)
    {
        inv_pow[i] = inv_pow[i - 1] * inv2 % mod;
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

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int MOD = 1e9 + 7;
// const int MAX_VAL = 2000;

// int main()
// {

//     while (T--)
//     {
//         int N, M;
//         cin >> N >> M;
//         N = min(N, MAX_VAL);
//         M = min(M, MAX_VAL);
//         ll total = 0;
//         vector<ll> res;
//         for (int i = 1; i <= M; i++)
//         {
//             if (i >= N)
//             {
//                 ll C = fact[i - 1] * inv_fact[N - 1] % MOD;
//                 C = C * inv_fact[i - N] % MOD;
//                 C = C * inv2_pows[i] % MOD;
//                 total = (total + C) % MOD;
//             }
//             res.push_back(total);
//         }
//         for (int i = 0; i < res.size(); i++)
//         {
//             if (i > 0)
//                 cout << ' ';
//             cout << res[i];
//         }
//         cout << '\n';
//     }
// }