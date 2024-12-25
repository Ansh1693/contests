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
string a, b;

void solve()
{
    int n, k;
    cin >> n >> k;
    cin >> a;
    cin >> b;

    if (a == b)
    {
        cout << 0 << nL;
        return;
    }

    int i = 0;
    int ind = -1;

    while (i < n)
    {
        int j = i + 1;

        while (j < n && b[j] == b[i])
            j++;

        if (j - i >= k)
        {
            ind = i;
            break;
        }

        i = j;
    }

    if (ind == -1)
    {
        cout << -1 << nL;
        return;
    }

    vector<pair<int, char>> ans;

    for (int i = 0; i < ind; i++)
    {
        ans.pb({i + 1, b[i]});
    }

    for (int i = n - 1; i >= ind + k; i--)
    {
        ans.push_back({i - k + 2, b[i]});
    }

    ans.pb({ind + 1, b[ind]});

    cout << ans.size() << nL;

    for (auto x : ans)
    {
        cout << x.F << " " << x.S << nL;
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