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
int a[501][501];

void solve()
{
    cin >> n;
    bool ch = 1;
    loop(i, 0, n)
    {
        loop(j, 0, n)
        {
            cin >> a[i][j];
            ch = ch & a[i][j] >= 0;
        }
    }

    if (ch)
    {
        cout << 0 << nL;
        return;
    }

    int ans = 0;
    loop(i, 0, n)
    {
        loop(j, 0, n)
        {
            if (a[i][j] < 0)
            {
                // cout << i << " " << j << nL;
                ans += abs(a[i][j]);
                // loop(k, 1, j)
                // {
                //     a[i + k][j - k] -= a[i][j];
                // }

                loop(k, j + 1, n)
                {
                    if (i + k - j >= n)
                        break;
                    a[i + k - j][k] -= a[i][j];
                }

                a[i][j] = 0;
            }
        }
    }

    // loop(i, 0, n)
    // {
    //     loop(j, 0, n) cout << a[i][j] << " ";

    //     cout << nL;
    // }

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
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}