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

void solve()
{
    cin >> n;
    vi a(n), b(n);
    bool ch = true;
    loop(i, 0, n)
    {
        cin >> a[i];
        if (i > 0 && ch)
        {
            ch = a[i] > a[i - 1];
        }
    }

    if (ch)
    {
        cout << (n * (n + 1)) / 2 << nL;
        return;
    }
    else
    {
        int ans = 0;
        int i = 1;
        while (i < n)
        {
            int j = i;
            while (j < n && a[j] > a[j - 1])
            {
                j++;
            }

            int len = j - i;

            ans += (len * (len + 1)) / 2;

            i = j;
        }

        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                b = a;

                swap(b[i], b[j]);
                int cnt = 0;

                int k = 1;
                while (k < n)
                {
                    int l = k;
                    while (l < n && a[l] > a[l - 1])
                    {
                        j++;
                    }

                    int len = l - k;

                    cnt += (len * (len + 1)) / 2;

                    k = l;
                }

                ans = max(ans, cnt);
            }
        }

        cout << ans << nL;
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