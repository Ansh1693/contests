#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long int
#define nL "\n"
#define pb push_bxzk
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
    int n;
    cin >> n;
    vi v(n);
    loop(i, 0, n)
    {
        cin >> v[i];
    }

    // map<tuple<int, int, int>, vvi> mp;
    // int cnt = 0;

    // loop(i, 0, n - 2)
    // {
    //     mp[make_tuple(a[i], a[i + 1], -1)].pb({a[i], a[i + 1], a[i + 2]});
    //     mp[make_tuple(a[i], -1, a[i + 2])].pb({a[i], a[i + 1], a[i + 2]});
    //     mp[make_tuple(-1, a[i + 1], a[i + 2])].pb({a[i], a[i + 1], a[i + 2]});
    // }

    // for (const auto &[key, count] : mp)
    // {
    //     for (int i = 0; i < count.size(); i++)
    //     {
    //         for (int j = i; j < count.size(); j++)
    //         {
    //             if (i != j)
    //             {
    //                 int diff = 0;
    //                 if (count[i][0] != count[j][0])
    //                 {
    //                     diff++;
    //                 }
    //                 if (count[i][1] != count[j][1])
    //                 {
    //                     diff++;
    //                 }
    //                 if (count[i][2] != count[j][2])
    //                 {
    //                     diff++;
    //                 }
    //                 if (diff == 1)
    //                 {
    //                     cnt++;
    //                 }
    //             }
    //         }
    //     }
    // }

    // cnt /= 2;

    map<pair<int, int>, int> xy;
    map<pair<int, int>, int> yz;
    map<pair<int, int>, int> xz;
    map<tuple<int, int, int>, int> xy3;
    map<tuple<int, int, int>, int> yz3;
    map<tuple<int, int, int>, int> xz3;
    int cnt = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int a = v[i];
        int b = v[i + 1];
        int c = v[i + 2];

        xy[{a, b}]++;
        yz[{b, c}]++;
        xz[{a, c}]++;

        tuple<int, int, int> triple = {a, b, c};
        xy3[triple]++;
        yz3[triple]++;
        xz3[triple]++;

        cnt += xy[{a, b}] - xy3[triple];
        cnt += yz[{b, c}] - yz3[triple];
        cnt += xz[{a, c}] - xz3[triple];
    }

    cout << cnt << nL;
}
signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
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