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
    int x1, x2, y1, y2, z1, z2, k;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> k;

    int diffx = abs(x1 - x2);
    int diffy = abs(y1 - y2);
    int diffz = abs(z1 - z2);

    int fi = max(diffx, max(diffy, diffz));
    int th = min(diffx, min(diffy, diffz));
    int sec = diffx + diffy + diffz - fi - th;

    int ans = fi;
    int thh =
        int ex = fi / k;

    if (ex > th + sec)
    {
    }

    ans += (diffx / k);
    ans += (diffy / k);
    ans += (diffz / k);
    ans -= (diffx % k == 0);
    ans -= (diffy % k == 0);
    ans -= (diffz % k == 0);

    // ans += (diffx + diffy + diffz) / k;

    ans -= ((diffx + diffy + diffz) % k == 0);

    cout << ans << nL;
}

//   int x1, x2, y1, y2, z1, z2, k;
//     cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> k;

//     int diffx = abs(x1 - x2);
//     int diffy = abs(y1 - y2);
//     int diffz = abs(z1 - z2);

//     int fi = max(diffx, max(diffy, diffz));
//     int th = min(diffx, min(diffy, diffz));
//     int sec = diffx + diffy + diffz - fi - th;

//     int ans = fi;

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