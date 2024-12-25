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
pii a[200005];
int l, r;
void solve()
{
    cin >> n;
    loop(i, 0, n)
    {
        cin >> a[i].F >> a[i].S;
    }

    sort(a, a + n);

    // loop(i, 0, n)
    // {
    //     cout << a[i].F << " " << a[i].S << nL;
    // }

    int maxi = 1;
    loop(i, 0, n)
    {
        l = a[i].F;
        r = a[i].S;
        int curr = 1;
        loop(j, 0, n)
        {
            if (i == j)
                continue;

            if (a[j].S > r && a[j].F >= l)
            {
                if (a[j].F <= a[i].F && a[j].S >= a[i].S)
                    continue;
                curr++;
                // cout << i << " " << j << nL;
                l = min(l, a[j].F);
                r = max(r, a[j].S);
            }
            else if (a[j].F < l && a[j].S <= r)
            {
                if (a[j].F <= a[i].F && a[j].S >= a[i].S)
                    continue;
                curr++;
                // cout << i << " " << j << nL;
                l = min(l, a[j].F);
                r = max(r, a[j].S);
            }
        }

        maxi = max(maxi, curr);
    }

    cout << maxi << nL;
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