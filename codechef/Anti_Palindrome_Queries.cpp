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
int n, q;
int cnt[200005][3];
int x;
int l, r;

void solve()
{
    cin >> n >> q;
    memset(cnt, 0, sizeof(cnt));
    loop(i, 1, n + 1)
    {
        loop(j, 0, 3)
        {
            cnt[i][j] += cnt[i - 1][j];
        }
        cin >> x;
        cnt[i][x - 1]++;
    }

    loop(i, 0, q)
    {
        cin >> l >> r;
        l--, r--;

        int sz = r - l + 1;

        if (sz % 2)
            cout << "No" << nL;
        else
        {
            int cnt1 = cnt[r + 1][0] - cnt[l][0];
            int cnt2 = cnt[r + 1][1] - cnt[l][1];
            int cnt3 = cnt[r + 1][2] - cnt[l][2];

            if (cnt1 == sz / 2 || cnt2 == sz / 2 || cnt3 == sz / 2)
                cout << "Yes" << nL;
            else
                cout << "No" << nL;
        }
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