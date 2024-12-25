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

int a[300001], c[300001], p[300001];
bool v[300001];
vector<int> t[300001];

void solve()
{
    int n, pMin = 1e9;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        p[i] = -1;
        c[i] = 0;
        v[i] = false;
        t[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        p[a[i]] = i;
        t[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (p[i] != -1)
        {
            c[p[i]]++;
            pMin = min(pMin, p[i]);
        }
    vector<int> r;
    for (int i = 1; i <= n;)
    {
        if (i == pMin)
        {
            r.push_back(a[i]);
            c[p[a[i]]]--;
            while (c[pMin] == 0 && pMin <= n)
                pMin++;
            i++;
        }
        else
        {
            if (r.size() % 2 == 0)
            {
                int m = 0;
                for (int j = i; j <= min(pMin, n); ++j)
                    if (!v[j])
                        m = max(m, a[j]);
                for (int j = i; j <= min(pMin, n); ++j)
                    if (a[j] == m)
                    {
                        i = j + 1;
                        break;
                    }
                if (m == 0)
                    break;
                r.push_back(m);
                c[p[m]]--;
                while (c[pMin] == 0 && pMin <= n)
                    pMin++;
            }
            else
            {
                int m = 1e9;
                for (int j = i; j <= min(pMin, n); ++j)
                    if (!v[j])
                        m = min(m, a[j]);
                for (int j = i; j <= min(pMin, n); ++j)
                    if (a[j] == m)
                    {
                        i = j + 1;
                        break;
                    }
                if (m == 1e9)
                    break;
                r.push_back(m);
                c[p[m]]--;
                while (c[pMin] == 0 && pMin <= n)
                    pMin++;
            }
        }
        for (int idx : t[r.back()])
            v[idx] = true;
    }
    cout << r.size() << endl;
    for (int x : r)
        cout << x << ' ';
    cout << endl;
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