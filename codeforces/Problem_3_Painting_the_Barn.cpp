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
const int MAX_N = 201;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    vvi field(MAX_N, vi(MAX_N, 0));
    loop(i, 0, n)
    {
        cin >> a >> b >> c >> d;
        field[a][b]++;
        field[c][d]++;
        field[a][d]--;
        field[c][b]--;
    }

    int cnt = 0;

    loop(i, 1, MAX_N)
    {
        loop(j, 1, MAX_N)
        {
            field[i][j] += field[i][j - 1] + field[i - 1][j] - field[i - 1][j - 1];

            if (field[i][j] == k)
                cnt++;

            if (i <= 9 && j <= 9)
            {
                cout << field[i][j] << "  ";
            }
        }

        cout << nL;
    }
    cout << cnt << nL;
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