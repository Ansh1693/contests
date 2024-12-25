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
int n, d, k;
int a[200009];
int b[200009];
int l, r;
void solve()
{
    cin >> n >> d >> k;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    vector<pii> q;
    loop(i, 0, k)
    {
        cin >> l >> r;
        l--, r--;
        a[l]++;
        b[r + 1]--;
    }

    // sort(inter, inter + k);
    int maxi = 0;
    int mini = k + 1;

    int maxii = 0;
    int minii = 0;

    int curr = 0;

    loop(i, 0, d)
    {
        if (a[i] > 0)
            curr += a[i];
    }

    loop(i, d, n)
    {
        curr += b[i - d];
        if (curr > maxi)
        {
            maxi = curr;
            maxii = i - d;
        }
        if (curr < mini)
        {
            mini = curr;
            minii = i - d;
        }

        if (a[i] > 0)
            curr += a[i];
    }

    if (curr > maxi)
    {
        maxi = curr;
        maxii = n - d;
    }

    cout << maxii + 1 << " " << minii + 1 << nL;
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