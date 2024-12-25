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
int n, m;
int a[300005];
int b[300005];
pii ai[300005];

void solve()
{
    cin >> n >> m;
    int maxi = 0;
    loop(i, 1, n + 1)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
        ai[i - 1] = {a[i], i};
        a[i] += a[i - 1];
    }
    int maxib = 0;
    loop(i, 1, m + 1)
    {
        cin >> b[i];
        maxib = max(maxib, b[i]);
    }

    if (maxib < maxi)
    {
        cout << -1 << nL;
        return;
    }

    int k = 1;
    sort(ai, ai + n, greater<pii>());
    int i = 1;
    int j = 0;
    int ans = 0;
    while (i <= n)
    {
        int sum = a[ai[j].S] - a[i - 1];
        int mini = INT_MAX;
        int kmi = k;
        int minK = k;

        while (ai[j].F <= b[kmi] && kmi <= m)
        {
            int mvs = sum / b[kmi];
            if (sum % b[kmi] != 0)
            {
                mvs++;
            }

            mvs *= (m - kmi);
            // cout << kmi << " " << mvs << nL;

            if (mvs < mini)
            {
                mini = mvs;
                minK = kmi;
            }
            kmi++;
        }

        // cout << ai[j].F << " " << b[minK] << " " << mini << nL;

        i = ai[j].S + 1;
        j++;
        k = minK;
        ans += mini;
    }

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