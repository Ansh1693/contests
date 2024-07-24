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

bool helper(vi &a, vi &calc, int c, int n)
{
    int prod = 0;
    loop(i, 0, n)
    {
        if (calc[i] == 0)
            continue;
        loop(j, 0, n)
        {
            if (calc[j] == 0)
                prod += a[i] * a[j];
        }
    }
    if (prod <= c)
        return true;

    return false;
}

void solve()
{

    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    loop(i, 0, n) { cin >> a[i]; }
    vi calc(n, 0);
    calc[0] = 1;

    if (helper(a, calc, c, n))
        cout << 1 << endl;
    else
    {
        int ch = 1;
        while (ch < n)
        {
            int mi = -1;
            loop(i, 0, n)
            {
                if (calc[i] == 0 && (mi == -1 || a[i] > a[mi]))
                    mi = i;
            }
            calc[mi] = 1;
            ch++;
            if (helper(a, calc, c, n))
            {
                cout << ch << endl;
                return;
            }
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