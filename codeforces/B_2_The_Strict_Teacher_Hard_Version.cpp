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
int n, m, q;
int mpos[100005];
int x;

void solve()
{
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++)
    {
        cin >> mpos[i];
    }

    sort(mpos, mpos + m);

    // loop(i, 0, m)
    // {
    //     cout << mpos[i] << " ";
    // }
    // cout << nL;

    loop(i, 0, q)
    {
        cin >> x;

        if (x < mpos[0])
        {
            cout << mpos[0] - 1 << nL;
            continue;
        }
        else if (x > mpos[m - 1])
        {
            cout << n - mpos[m - 1] << nL;
            continue;
        }
        else
        {
            int l = 0, r = m - 1;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (mpos[mid] < x)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }

            int m1 = mpos[l];
            int m2 = mpos[l - 1];

            int tot = abs(m1 - x) + abs(m2 - x);

            if (abs(m1 - x) == abs(m2 - x))
            {
                cout << abs(m1 - x) << nL;
                continue;
            }
            else
            {
                cout << tot / 2 << nL;
                continue;
            }
        }
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