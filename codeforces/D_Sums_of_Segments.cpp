#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define aint(x) (x).begin(), (x).end()
#define forEqual(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b - 1; i >= a; i--)
#define sortaint(x) sort(aint(x))
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
int n, t;
int l, r;
int a[300005];
int pre[300005];
int wt[300005];
int sumpre[300005];
int sumprewt[300005];

void solve()
{
    cin >> n;

    loop(i, 1, n + 1)
            cin >>
        a[i];

    loop(i, 1, n + 1)
    {
        pre[i] = pre[i - 1] + a[i];
        wt[i] = wt[i - 1] + i * a[i];
        sumpre[i] = sumpre[i - 1] + pre[i];
        sumprewt[i] = sumprewt[i - 1] + wt[i];
    }

    // loop(i, 1, n + 1)
    // {
    //     cout << wt[i] << " ";
    // }
    // cout << nL;

    vector<int> sum_blocks(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        sum_blocks[i] = sum_blocks[i - 1] + n - i + 1;
    }

    int C = (n + 1) * pre[n] - wt[n];

    auto get_sum_b = [&](int k) -> int
    {
        if (k == 0)
            return 0;

        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (sum_blocks[mid] >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        int l = left;
        int left1 = (l > 1) ? sum_blocks[l - 1] : 0;
        int p = k - left1;

        int term1 = l * C;
        int term2 = (n + 1) * ((l - 2) >= 0 ? ((l - 2) >= 1 ? sumpre[l - 2] : 0) : 0);
        int term3 = (l - 2) >= 0 ? ((l - 2) >= 1 ? sumprewt[l - 2] : 0) : 0;

        int left2 = 0;
        if (l > 2)
        {
            left2 = sumpre[l - 2];
        }

        int sum_left2 = 0;
        if (l >= 2)
        {
            sum_left2 = sumprewt[l - 2];
        }

        term2 -= (n + 1) * left2;
        term3 = sum_left2;

        int pre_sum = pre[l + p - 1] - pre[l - 1];
        int wt_sum = wt[l + p - 1] - wt[l - 1];
        int term4 = (p + l) * pre_sum;
        int term5 = wt_sum;

        return ((l - 1) * C - (n + 1) * left2 + sum_left2) + (term4 - term5);
    };

    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        int sumr = get_sum_b(r);
        int suml = get_sum_b(l - 1);
        cout << (sumr - suml) << nL;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}