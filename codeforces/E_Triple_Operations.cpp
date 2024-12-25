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

vi arr;

int ret(int l, int r)
{
    int ans = 0;
    int og = l;
    for (int i = 1; i < 21; i++)
    {
        // min one
        if (og == l)
            ans++;

        if (r >= arr[i - 1] + 1)
            ans += r - l + 1;

        // cout << i << " " << l << " " << r << " " << ans << endl;
        if (l <= arr[i])
            l = arr[i] + 1;

        if (arr[i] > r)
            break;
    }

    return ans;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 1;
    int mini = 1e9;

    cout << ret(l, r) << nL;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    // #endif
    arr.resize(21, 1);
    arr[0] = 1;
    for (int i = 1; i < 21; i++)
    {
        arr[i] = arr[i - 1] * 3;
    }

    for (int i = 0; i < 21; i++)
    {
        arr[i]--;
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}