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
    int n, m, r;
    cin >> n >> m >> r;

    vi cows(n, 0);
    loop(i, 0, n) { cin >> cows[i]; }
    vector<pii> milk(m);
    loop(i, 0, m) { cin >> milk[i].F >> milk[i].S; }
    vi rent(r);
    loop(i, 0, r) cin >> rent[i];

    auto cmp = [&](const pair<int, int> &c1, const pair<int, int> &c2)
    {
        return c1.second > c2.second;
    };
    sort(all(cows), greater<int>());
    sort(all(milk), cmp);
    sort(all(rent), greater<int>());

    int ans = 0;

    int mi = 0; // milk
    int rn = 0; // rent
    int i = 0;  // cow

    while (i < n)
    {
        int rental = rent[rn];
        int milkCost = 0;
        int cnt = cows[i];
        int j = mi;
        while (cnt > 0 && j < m)
        {
            if (cnt > milk[j].F)
            {
                milkCost += milk[j].F * milk[j].S;
                cnt -= milk[j].F;
                j++;
            }
            else
            {
                milkCost += cnt * milk[j].S;
                cnt = 0;
            }
        }

        // cout << cows[i] << "  " << rental << "  " << milkCost << nL;
        if (rn >= r || milkCost >= rental)
        {

            ans += milkCost;
            int cnt = cows[i];
            while (cnt > 0 && mi < m)
            {
                if (cnt > milk[mi].F)
                {
                    cnt -= milk[mi].F;
                    mi++;
                }
                else
                {
                    milk[mi].F -= cnt;
                    if (milk[mi].F == 0)
                        mi++;
                    cnt = 0;
                }
            }
            i++;
        }
        else
        {
            ans += rental;
            rn++;
            n--;
        }
    }

    cout << ans << nL;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
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