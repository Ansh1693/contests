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
int n, q;
int a[100005];
int l, r, k;

int mini()
{
    int tot = 0;
    loop(i, l, r) tot += abs(a[i + 1] - a[i]);

    if (tot <= k)
    {
        return 0;
    }

    vector<int> v;
    loop(i, l, r + 1) v.pb(a[i]);

    int mvs = 0;

    loop(i, 1, v.size() - 1)
    {
        if (v[i] > v[i - 1] && v[i] > v[i + 1])
        {
            int m = max(v[i - 1], v[i + 1]);
            v[i] = m;

            int m1 = abs(v[i] - m);

            if (m1 * 2 > tot - k)
            {
                mvs += (tot - k) / 2;

                tot = k;
            }
            else
            {
                mvs += m1;
                tot -= m1 * 2;
            }
        }

        if (v[i] < v[i - 1] && v[i] < v[i + 1])
        {
            int m = min(v[i - 1], v[i + 1]);
            v[i] = m;

            int m1 = abs(v[i] - m);

            if (m1 * 2 > tot - k)
            {
                mvs += (tot - k) / 2;

                tot = k;
            }
            else
            {
                mvs += m1;
                tot -= m1 * 2;
            }
        }

        if (tot <= k)
        {
            return mvs;
        }
    }
}

void solve()
{
    cin >> n >> q;
    loop(i, 0, n) cin >> a[i];
    while (q--)
    {
        cin >> l >> r >> k;
        l--, r--;

        cout << mini() << nL;
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