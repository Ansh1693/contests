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

string s;
pii a[100005];

void solve()
{
    cin >> s;
    a[0] = {0, 0};
    int n = s.size();
    int cntA = 0, cntB = 0;
    loop(i, 0, n)
    {
        if (s[i] == 'A')
        {
            cntA++;
        }
        else
        {
            cntB++;
        }

        a[i + 1] = {cntA, cntB};
    }

    if (cntA % 2 || cntB % 2)
    {
        cout << "NO" << nL;

        return;
    }

    cntA /= 2;
    cntB /= 2;
    int k = cntA + cntB;

    // loop(i, 0, n + 1)
    // {
    //     cout << i << " " << a[i].F << " " << a[i].S << nL;
    // }

    loop(i, k, n)
    {
        if (a[i].F - a[i - k].F == cntA && a[i].S - a[i - k].S == cntB)
        {
            cout << "YES" << nL;
            cout << i - k + 1 << " " << i + 1 << nL;

            return;
        }
    }

    cout << "NO" << nL;
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