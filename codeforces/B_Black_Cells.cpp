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
int a[200001];

bool good(int k)
{
    int i = 1;
    int cnt = 0;

    while (i < n)
    {
        if (a[i] - a[i - 1] > k)
        {
            cnt++;
            if (n % 2 && cnt > 1)
                return false;
            if (n % 2 == 0 && cnt > 0)
                return false;
            i++;
        }
        else
        {
            i += 2;
        }
    }

    return true;
}

void solve()
{
    cin >> n;
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 1 << nL;
        return;
    }

    int l = 0, r = LLONG_MAX;

    while (l < r)
    {
        int m = (l + r) >> 1;
        if (good(m))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << l << nL;
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