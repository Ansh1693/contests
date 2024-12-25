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
    cin >> n;
    cin >> s;

    if (n % 2)
    {
        vvi pref(2, vi(26, 0));
        vvi suff(2, vi(26, 0));

        loop(i, 0, n)
        {
            suff[i % 2][s[i] - 'a']++;
        }

        int res = n;

        for (int i = 0; i < n; i++)
        {
            suff[i % 2][s[i] - 'a']--;
            int ans = n;
            for (int k = 0; k < 2; k++)
            {
                int mx = 0;
                for (int j = 0; j < 26; j++)
                {
                    mx = max(mx, pref[1 - k][j] + suff[k][j]);
                }

                ans -= mx;
            }

            res = min(res, ans);
            pref[i % 2][s[i] - 'a']++;
        }

        cout << res << nL;
    }
    else
    {
        vi a(26, 1e9);

        for (int i = 0; i < n; i += 2)
        {
            if (a[s[i] - 'a'] != 1e9)
            {
                a[s[i] - 'a']++;
            }
            else
            {
                a[s[i] - 'a'] = 1;
            }
        }

        int even = 1e9;

        for (int i = 0; i < 26; i++)
        {
            if (a[i] != 1e9)
            {
                even = min(even, n / 2 - a[i]);
            }
        }

        a = vi(26, 1e9);

        for (int i = 1; i < n; i += 2)
        {
            if (a[s[i] - 'a'] != 1e9)
            {
                a[s[i] - 'a']++;
            }
            else
            {
                a[s[i] - 'a'] = 1;
            }
        }

        int odd = 1e9;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != 1e9)
            {
                odd = min(odd, n / 2 - a[i]);
            }
        }

        cout << (even + odd) << nL;
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