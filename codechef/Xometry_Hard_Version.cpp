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
int a[5001];
vi b;

void solve()
{
    b.assign(1 << 20, 0);
    cin >> n;
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    int ans = 0;

    loop(i, 0, n)
    {
        loop(j, i + 1, n)
        {
            int x = a[i] ^ a[j];

            ans += b[x];
            b[x]++;
        }
    }

    // int k, l;

    // loop(i, 0, n)
    // {
    //     loop(j, i + 1, n)
    //     {
    //         if (i != j)
    //         {
    //             int x = a[i] ^ a[j];
    //             // for (auto p : mp2[x])
    //             // {
    //             //     if (p.F != i && p.F != j && p.S != i && p.S != j)
    //             //     {
    //             //         k = p.F;
    //             //         l = p.S;

    //             //         // s.insert({{i, j}, p});

    //             //         // i j k l -> i l j k
    //             //         // j i l k -> j k i l
    //             //         if (a[i] ^ a[l] == a[j] ^ a[k])
    //             //         {
    //             //             ans += 2;
    //             //         }

    //             //         // i j l k -> i k j l
    //             //         // j i k l -> j l i k
    //             //         if (a[i] ^ a[k] == a[j] ^ a[l])
    //             //         {
    //             //             ans += 2;
    //             //         }
    //             //     }
    //             // }

    //             int y = mp2[x].size();

    //             ans += max(0LL, (y - 1) * 4);
    //         }
    //     }
    // }

    // for (auto p : mp2)
    // {
    //     int x = p.F;
    //     int y = p.S;

    //     int pairs = y * (y - 1);
    //     ans += max(0LL, pairs * 4);
    // }
    cout << ans * 8 << nL;
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