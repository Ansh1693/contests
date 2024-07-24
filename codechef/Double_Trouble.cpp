#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define aint(x) (x).begin(), (x).end()
#define forEqual(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b - 1; i >= a; i--)
#define sortaint(x) sort(aint(x))
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
    vi a(n), b(n);
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    loop(i, 0, n)
    {
        cin >> b[i];
    }

    int ch = 0;
    int k = 1;

    loop(i, 0, n)
    {
        if (i == n - 1)
            break;

        if (a[i] + b[i] < a[i + 1])
        {
            k++;
        }
    }

    if (k <= 2)
    {
        ch = 1;
    }

    k = 1;

    rloop(i, 0, n)
    {
        if (i == 0)
            break;

        if (a[i] - b[i] > a[i - 1])
        {
            k++;
        }
    }

    if (k <= 2)
    {
        ch = 1;
    }

    int pre = 0;

    loop(i, 0, n - 1)
    {
        if (a[i] + b[i] >= a[i + 1])
        {
            pre++;
        }
        else
        {
            break;
        }
    }
    int suf = n - 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] - b[i] <= a[i - 1])
        {
            suf--;
        }
        else
        {
            break;
        }
    }

    if (pre + 1 >= suf)
    {
        ch = 1;
    }

    if (ch)
    {
        cout << "YES" << nL;
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] - b[i] <= a[i - 1])
        {
            continue;
        }
        else
        {
            for (int j = i; j < n; j++)
            {
                if (j == n - 1)
                    ch = 1;
                if (a[j] + b[j] >= a[j + 1])
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            break;
        }
    }

    if (ch)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
