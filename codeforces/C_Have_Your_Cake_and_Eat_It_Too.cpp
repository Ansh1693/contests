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

void find(vector<int> &a, int n, int target, vector<pair<int, int>> &ans)
{
    int i = 1;
    int j = 0;

    while (i <= n)
    {
        while (a[i] - a[j] >= target && j < i)
        {
            ans.push_back({j + 1, i});
            j++;
        }
        i++;
    }
}

bool check(int la, int ea, int lb, int eb, int lc, int ec)
{
    if (max(la, lb) <= min(ea, eb))
    {
        return 0;
    }
    if (max(la, lc) <= min(ea, ec))
    {
        return 0;
    }

    if (max(lb, lc) <= min(eb, ec))
    {
        return 0;
    }

    return 1;
}

char check(int la, int ea, int lb, int eb)
{
    if (max(la, lb) <= min(ea, eb))
    {
        return 0;
    }

    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    int x = 0;
    loop(i, 0, n)
    {
        cin >> x;
        a[i + 1] = a[i] + x;
    }
    loop(i, 0, n)
    {
        cin >> x;
        b[i + 1] = b[i] + x;
    }
    loop(i, 0, n)
    {
        cin >> x;
        c[i + 1] = c[i] + x;
    }

    int tar = a[n] / 3;
    tar += a[n] % 3 != 0;
    vector<pair<int, int>> vA;
    vector<pair<int, int>> vB;
    vector<pair<int, int>> vC;
    find(a, n, tar, vA);
    find(b, n, tar, vB);
    find(c, n, tar, vC);

    sort(all(vA));
    sort(all(vB));
    sort(all(vC), greater<pair<int, int>>());

    loop(i, 0, vA.size())
    {
        loop(j, 0, vB.size())
        {
            loop(k, 0, vC.size())
            {
                if (check(vA[i].F, vA[i].S, vB[j].F, vB[j].S, vC[k].F, vC[k].S))
                {
                    cout << vA[i].F << " " << vA[i].S << " " << vB[j].F << " " << vB[j].S << " " << vC[k].F << " " << vC[k].S << nL;
                    return;
                }
            }
        }
    }

    cout << -1 << nL;
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