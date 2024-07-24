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
    int n, m;
    cin >> n >> m;

    vvi a(n, vi(m));
    string s;
    loop(i, 0, n)
    {
        cin >> s;
        loop(j, 0, m)
        {
            a[i][j] = s[j] - '0';
        }
    }

    loop(i, 0, n)
    {
        cin >> s;
        loop(j, 0, m)
        {
            a[i][j] = ((s[j] - '0') - a[i][j] + 3) % 3;
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            if (a[i][j] != 0)
            {
                int d = a[i][j];
                a[i][j] = (a[i][j] - d + 3) % 3;
                a[i][j + 1] = (a[i][j + 1] - (3 - d) % 3 + 3) % 3;
                a[i + 1][j + 1] = (a[i + 1][j + 1] - d + 3) % 3;
                a[i + 1][j] = (a[i + 1][j] - (3 - d) % 3 + 3) % 3;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] != 0)
            {

                cout << "NO" << nL;
                return;
            }
        }
    }

    cout << "YES" << nL;
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
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}