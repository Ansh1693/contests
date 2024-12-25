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
string s;

void solve()
{
    vi a;
    vi b;
    cin >> n;
    cin >> s;

    bool ch = 1;
    loop(i, 0, n)
    {
        if (s[i] != '1')
            ch = 0;

        if (s[i] == '0')
            a.pb(i);

        if (s[i] == '1')
            b.pb(i);
    }

    if (ch)
    {
        n = (n + 1) / 2;
        n = (n * (n + 1)) / 2;
        cout << n << nL;

        return;
    }

    int ans = (n * (n + 1)) / 2;

    reverse(all(b));
    int n0 = a.size();
    int n1 = b.size();
    n0--;
    n1--;

    for (int i = n - 1; i >= 0; i--)
    {
        while (n0 >= 0 && a[n0] >= i)
            n0--;
        while (n1 >= 0 && b[n1] >= i)
            n1--;
        if (s[i] == '1')
        {
            if (n0 >= 0)
            {
                ans -= i + 1;
                n0--;
            }
            else if (n1 >= 0)
            {
                ans -= i + 1;
                n1--;
            }
        }
    }
    cout << ans << endl;
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