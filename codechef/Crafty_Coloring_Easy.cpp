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
int n, m, k;
int mini;
string s;
pii r[1000005];
pii c[1000005];

void solve()
{
    cin >> n >> m >> k;
    cin >> s;

    mini = min(n, m);
    int mv = 1;
    int i = 0;
    int red = 0;
    int blue = 0;
    while (mv <= mini)
    {
        if (s[i] == 'A')
        {
            r[mv] = {0, mv};
            c[mv] = {0, mv};
        }
        else if (s[i] == 'B')
        {
            r[mv] = {1, mv};
            c[mv] = {1, mv};
        }

        mv++;
        i++;
        i = i % k;
    }

    // loop(i, 1, mini + 1)
    // {
    //     loop(j, 1, mini + 1)
    //     {
    //         int colr = r[i].F;
    //         int colc = c[j].F;
    //         int mvr = r[i].S;
    //         int mvc = c[j].S;

    //         if (mvc > mvr)
    //         {
    //             if (colc == 0)
    //             {
    //                 red++;
    //             }
    //             else
    //             {
    //                 blue++;
    //             }
    //         }
    //         else
    //         {
    //             if (colr == 0)
    //             {
    //                 red++;
    //             }
    //             else
    //             {
    //                 blue++;
    //             }
    //         }

    //         // cout << colr << " " << colc << " " << mvr << " " << mvc << " " << red << " " << blue << nL;
    //     }
    // }

    if (n > mini)
    {
        loop(i, 0, m)
        {
            int col = c[i + 1].F;
            if (col == 0)
            {
                red += n - mini;
            }
            else
            {
                blue += n - mini;
            }
        }
    }

    if (m > mini)
    {
        loop(i, 0, n)
        {
            int col = r[i + 1].F;
            if (col == 0)
            {
                red += m - mini;
            }
            else
            {
                blue += m - mini;
            }
        }
    }

    if (red > blue)
    {
        cout << "Alice" << nL;
    }
    else if (red < blue)
    {
        cout << "Bob" << nL;
    }
    else
    {
        cout << "Draw" << nL;
    }

    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
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