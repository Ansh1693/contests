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
int n, m;
string a[300005];

void solve()
{
    cin >> m >> n;
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    int ans = 0;
    int tot, cnt0s, cnt1s, diff;

    loop(i, 0, m)
    {
        cnt0s = 0;
        cnt1s = 0;
        loop(j, 0, n)
        {
            if (a[j][i] == '0')
            {
                cnt0s++;
            }
            else if (a[j][i] == '1')
            {
                cnt1s++;
            }
        }

        tot = cnt0s + cnt1s;

        tot = n - tot;

        if (cnt0s > cnt1s)
        {
            diff = min(tot, cnt0s - cnt1s);
            cnt1s += diff;
            tot -= diff;
        }
        else if (cnt1s > cnt0s)
        {
            diff = min(tot, cnt1s - cnt0s);
            cnt0s += diff;
            tot -= diff;
        }

        cnt0s += tot / 2;
        cnt1s += tot / 2 + tot % 2;

        ans += cnt0s * cnt1s;
    }

    cout << ans << nL;

    // loop(i, 0, m)
    // {
    //     cout << cnt0[i] << nL;
    // }
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