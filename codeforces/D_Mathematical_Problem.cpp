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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi a(n);
    bool check = false;
    loop(i, 0, n)
    {
        a[i] = s[i] - '0';
        check |= a[i] == 0;
    }

    if (n == 2)
    {
        if (a[0] == 0)
        {
            cout << a[1] << nL;
            return;
        }
        else
        {
            cout << s << nL;
            return;
        }
    }

    int ans = 1e18;

    if (check)
    {
        if (n >= 4)
        {
            cout << 0 << endl;
        }
        else
        {
            if (a[1] == 0)
            {

                cout << min(a[0] + a[2], a[0] * a[2]) << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        vi arr;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                arr.push_back(a[j]);
            }
            else
            {
                arr.push_back(a[j] * 10 + a[j + 1]);
                j++;
            }
        }

        int res = arr[0];
        if (res == 1)
        {
            res = 0;
        }

        for (int i = 1; i < arr.size(); i++)
        {

            res = arr[i] == 1 ? res : res + arr[i];
        }

        ans = min(ans, res);
    }

    cout << ans << endl;
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