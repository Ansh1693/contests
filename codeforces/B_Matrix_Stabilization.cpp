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

void helper(vvi &arr, int i, int j, int n, int m)
{
    int currentValue = arr[i][j];
    if (i > 0 && arr[i - 1][j] >= currentValue)
        return;
    if (i < n - 1 && arr[i + 1][j] >= currentValue)
        return;
    if (j > 0 && arr[i][j - 1] >= currentValue)
        return;
    if (j < m - 1 && arr[i][j + 1] >= currentValue)
        return;
    int maxi = INT_MIN;
    if (i > 0)
        maxi = max(maxi, arr[i - 1][j]);
    if (i < n - 1)
        maxi = max(maxi, arr[i + 1][j]);
    if (j > 0)
        maxi = max(maxi, arr[i][j - 1]);
    if (j < m - 1)
        maxi = max(maxi, arr[i][j + 1]);
    arr[i][j] = maxi;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            cin >> a[i][j];
        }
    }

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            helper(a, i, j, n, m);
            cout << a[i][j] << " ";
        }

        cout << nL;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    //  #endif
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}