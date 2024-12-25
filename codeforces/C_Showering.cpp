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
    int n, s, m;
    cin >> n >> s >> m;

    // vi a(m + 2, 0);

    int l1 = 0, r1 = 0, l, r;
    bool flag = false;
    loop(i, 0, n)
    {
        cin >> l >> r;

        if (l - r1 >= s)
        {
            flag = true;
        }
        // else
        //     cout << l << " " << r1 << l - r1 << nL;

        l1 = l;
        r1 = r;

        // cout << l1 << " " << r1 << nL;
    }

    if (m - r1 >= s)
    {
        flag = true;
    }

    // loop(i, 0, m + 2)
    // {
    //     a[i + 1] += a[i];
    // }

    // int tot = 0;
    // loop(i, 0, m + 1)
    // {
    //     cout << a[i] << " ";
    //     if (a[i] == 0)
    //     {
    //         tot++;
    //     }

    //     if (a[i] != 0)
    //         tot = 0;

    //     if (tot == s)
    // {
    //     cout << "YES" << nL;
    //     return;
    // }
    // }

    if (flag)
        cout << "YES" << nL;
    else
        cout << "NO" << nL;

    // cout << "NO" << nL;
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