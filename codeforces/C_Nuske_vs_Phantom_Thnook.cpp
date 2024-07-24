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
    int n, m, k;
    cin >> n >> m >> k;
    vvi arr(n + 1, vi(m + 1, 0));
    vvi pref(n + 1, vi(m + 1, 0));
    vvi hor(n + 1, vi(m + 1, 0));
    vvi ver(n + 1, vi(m + 1, 0));
    loop(i, 1, n + 1)
    {
        string s;
        cin >> s;
        loop(j, 1, m + 1)
        {
            arr[i][j] = (s[j - 1] == '1');
        }

        // cout << nL;
    }
    loop(i, 1, n + 1)
    {

        loop(j, 1, m + 1)
        {
            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
            // cout << arr[i][j] << "  ";
            if (arr[i][j])
            {
                if (!arr[i - 1][j] && !arr[i][j - 1])

                    pref[i][j]++;
                if (arr[i - 1][j] && arr[i][j - 1])
                    pref[i][j]--;
            }
            hor[i][j] = hor[i][j - 1];
            ver[i][j] = ver[i - 1][j];
            if (arr[i][j])
            {
                hor[i][j] += !arr[i][j - 1];
                ver[i][j] += !arr[i - 1][j];
            }
        }
    }

    int x1, x2, y1, y2;
    loop(i, 0, k)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = arr[x1][y1];

        ans += hor[x1][y2] - hor[x1][y1];
        ans += ver[x2][y1] - ver[x1][y1];

        ans += pref[x2][y2] + pref[x1][y1] - pref[x2][y1] - pref[x1][y2];

        cout << ans << nL;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}