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
    int n, k;
    cin >> n >> k;
    vvi field(2 * n - 1, vi(2 * n - 1, -1));
    vvi arr(2 * n, vi(2 * n, 0));

    int x;
    loop(i, 0, n)
    {
        loop(j, 0, n)
        {
            cin >> x;
            field[n + i - j - 1][i + j] = x;
        }
    }

    loop(i, 0, 2 * n - 1)
    {
        loop(j, 0, 2 * n - 1)
        {

            arr[i + 1][j + 1] += arr[i][j + 1];

            arr[i + 1][j + 1] += arr[i + 1][j];

            arr[i + 1][j + 1] -= arr[i][j];

            arr[i + 1][j + 1] += max(field[i][j], 0LL);
        }

        // cout << nL;
    }
    int maxi = 0;
    loop(i, k, 2 * n - k - 1)
    {
        loop(j, k, 2 * n - k - 1)
        {
            if (arr[i][j] == -1)
                continue;

            maxi = max(maxi, arr[i + k + 1][j + k + 1] - arr[i + 1 + k][j - k] - arr[i - k][j + 1 + k] + arr[i - k][j - k]);
        }
    }
    cout << maxi;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}