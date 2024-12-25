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
int l1, r1, l2, r2;

void solve()
{
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    vi pre(101, 0);
    int v = min(r1, r2) - max(l1, l2);

    if (min(l1, l2) < max(l1, l2))
    {
        pre[max(l1, l2) - 1] = 1;
    }
    if (min(r1, r2) < max(r1, r2))
    {
        pre[min(r1, r2)] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        ans += pre[i];
    }

    if (v < 0)
        ans = 0LL;
    cout << max(1LL, ans + max(0LL, min(r2, r1) - max(l1, l2))) << endl;
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