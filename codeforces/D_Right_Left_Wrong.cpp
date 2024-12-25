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
int a[200005];
string s;

void solve()
{
    cin >> n;
    a[0] = 0;
    loop(i, 1, n + 1)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> s;
    int l = 0, r = n - 1;
    while (l < n && s[l] == 'R')
    {
        l++;
    }
    while (r >= 0 && s[r] == 'L')
    {
        r--;
    }
    if (l > r)
    {
        cout << "0\n";
        return;
    }
    int ans = a[r + 1] - a[l];
    int i = l + 1;
    int j = r - 1;

    while (i < j)
    {
        while (i < j && s[i] == 'R')
        {
            i++;
        }
        while (i < j && s[j] == 'L')
        {
            j--;
        }

        if (i < j)
        {
            ans += a[j + 1] - a[i];
        }

        i++;
        j--;
    }

    // l++;
    // r--;

    cout << ans << nL;
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