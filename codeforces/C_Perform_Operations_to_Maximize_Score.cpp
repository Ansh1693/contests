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
int n, k;
vector<pii> a;

bool good(int x, int ch)
{
    int cnt = 0;
    int k1 = k;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == ch)
            continue;

        if (a[i].F >= x)
            cnt++;

        else if (a[i].S == 1 && a[i].F + k1 >= x)
        {
            k1 -= x - a[i].F;
            cnt++;
        }
    }

    return cnt >= (n + 1) / 2;
}

// 5 1 5 15 15

int getMed(int i)
{
    int l = 0, r = 3e9;
    while (l < r)
    {
        int m = (l + r) >> 1;
        if (good(m, i))
            l = m + 1;
        else
            r = m;
    }

    // cout << a[i].F << " " << l - 1 << nL;

    return l - 1;
}
// 2 5 8 9 10 12 13 14
// 1 1 1 1  1  0  0  0

void solve()
{
    cin >> n >> k;
    int maxZ = -1, maxO = -1;
    a.resize(n);
    loop(i, 0, n)
    {
        cin >> a[i].F;
    }
    loop(i, 0, n)
    {
        cin >> a[i].S;
    }

    sortall(a);

    loop(i, 0, n)
    {
        // cout << a[i].F << " " << a[i].S << nL;
        if (a[i].S == 1)
        {
            if (maxO == -1)
                maxO = i;
            maxO = a[maxO].F < a[i].F ? i : maxO;
        }
        else
        {
            if (maxZ == -1)
                maxZ = i;
            maxZ = a[maxZ].F < a[i].F ? i : maxZ;
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    if (maxZ != -1)
        ans1 = a[maxZ].F + getMed(maxZ);

    if (maxO != -1)
    {
        a[maxO].F += k;
        k = 0;
        ans2 = a[maxO].F + getMed(maxO);
    }

    cout << max(ans1, ans2) << nL;
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