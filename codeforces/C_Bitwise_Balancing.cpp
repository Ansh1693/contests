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
int b, c, d;

// a | b - (a&c) = d

void solve()
{
    cin >> b >> c >> d;

    int a = 0;
    bool ch = 1;

    loop(i, 0, 62)
    {
        bool b1 = b & (1LL << i);
        bool c1 = c & (1LL << i);
        bool d1 = d & (1LL << i);

        // cout << i + 1 << " " << b1 << " " << c1 << " " << d1 << " ";

        if (d1)
        {
            if (b1 && c1)
            {
                continue;
            }
            else if (b1 && !c1)
            {
                a |= (1LL << i);
            }
            else if (!b1 && c1)
            {
                ch = 0;
                break;
            }
            else
            {
                a |= (1LL << i);
            }
        }
        else
        {
            if (b1 && c1)
            {
                a |= (1LL << i);
            }
            else if (b1 && !c1)
            {
                ch = 0;
                break;
            }
            else if (!b1 && c1)
            {
                a |= (1LL << i);
            }
            else
            {
                continue;
            }
        }

        // cout << a << nL;
    }

    if (!ch)
    {
        cout << -1 << nL;
        return;
    }

    cout << a << nL;
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