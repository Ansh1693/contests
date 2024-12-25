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

vi arr;
vi arr2;

void pregen()
{
    arr.resize(500001);
    arr2.resize(500001);
    int res;
    arr[0] = 0;
    arr2[0] = 0;
    loop(i, 1, 500001)
    {

        res = i;
        res = res * (i + 1) * (2 * i + 1);
        res /= 6;

        res %= mod;

        arr[i] = (res) % mod;
        arr2[i] = (res + arr2[i - 1]) % mod;
    }
}

void solve()
{
    cin >> n;

    int ans = 0;

    loop(i, 1, n)
    {
        ans += (n - i) * arr2[i];

        ans %= mod;
        ans += arr[n - i];
        ans %= mod;
    }

    ans += ans;

    // int tot = pow(2, n);

    // loop(i, 0, tot / 2)
    // {

    //     int j = i;
    //     string s = "";

    //     while (j)
    //     {
    //         s.push_back((j % 2) + '0');
    //         j = j >> 1;
    //     }

    //     while (s.size() < n)
    //         s.push_back('0');

    //     reverse(all(s));

    //     cout << i << " " << s << nL;
    // }

    cout << ans % mod << nL;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    //  #endif
    pregen();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}