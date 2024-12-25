

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

bool isSorted(vector<int> &a)
{
    for (int i = 1; i < a.size(); ++i)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

void solve()
{
    cin >> n;
    vi a(n);
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    vector<pii> ans;
    if (isSorted(a))
    {
        cout << 0 << nL;
        return;
    }

    bool possible = true;

    while (!isSorted(a))
    {
        bool op = false;
        for (int len = 3; len <= a.size(); len += 2)
        {
            for (int i = 0; i + len - 1 < a.size(); ++i)
            {
                vi sub(a.begin() + i, a.begin() + i + len);
                vi so = sub;
                sortall(so);
                int median = so[len / 2];

                int median_index = -1;
                for (int j = 0; j < sub.size(); ++j)
                {
                    if (sub[j] == median)
                    {
                        median_index = j;
                        break;
                    }
                }

                if (median_index != -1)
                {
                    a.erase(a.begin() + i + median_index);
                    op = true;
                    ans.pb({i + 1, i + len});
                    break;
                }
            }
            if (op)
                break;
        }

        if (!op)
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        cout << ans.size() << nL;
        for (auto op : ans)
        {
            cout << op.F << " " << op.S << nL;
        }
    }
    else
    {
        cout << -1 << nL;
    }
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