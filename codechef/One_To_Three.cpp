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
int a[300005];
int b[300005];
int c[300005];
int sm = 0;

int atob(int sm)
{
    int curr = sm;
    loop(i, 1, n - 1)
    {
        if (b[i - 1] + b[i + 1] == 4 && b[i] == 3)
        {
            b[i] = 1;
            curr -= 2;
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        if (b[i - 1] + b[i + 1] == 4 && b[i] == 3)
        {
            b[i] = 1;
            curr -= 2;
        }
    }

    return curr;
}

int btoa(int sm)
{
    int curr = sm;
    for (int i = n - 1; i >= 1; i--)
    {
        if (c[i - 1] + c[i + 1] == 4 && c[i] == 3)
        {
            c[i] = 1;
            curr -= 2;
        }
    }
    loop(i, 1, n - 1)
    {
        if (c[i - 1] + c[i + 1] == 4 && c[i] == 3)
        {
            c[i] = 1;
            curr -= 2;
        }
    }

    return curr;
}

void solve()
{
    sm = 0;

    cin >> n;
    loop(i, 0, n)
    {
        cin >> a[i];
        // sm += a[i];
    }

    loop(i, 1, n - 1)
    {
        if (a[i - 1] + a[i + 1] == 4 && a[i] == 3)
        {
            a[i] = 1;
            // curr -= 2;
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i - 1] + a[i + 1] == 4 && a[i] == 3)
        {
            a[i] = 1;
            // curr -= 2;
        }
    }

    loop(i, 0, n) sm += a[i];

    cout << sm << nL;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    //  #endif
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}