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
int n, m;
string s, t;

int Z[4000005];

void getZarr(string str)
{
    int n = str.length();
    int L, R, k;
    memset(Z, 0, n * sizeof(int));

    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;

            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;

            if (Z[k] < R - i + 1)
                Z[i] = Z[k];

            else
            {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

void solve()
{

    cin >> n >> m;
    cin >> s >> t;

    if (s[0] != t[0])
    {
        cout << -1 << nL;
        return;
    }

    if (s == t)
    {
        cout << 0 << nL;
        return;
    }
    if (n == m && s != t)
    {
        cout << 2 << nL;
        return;
    }
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            break;
        }
    }

    if (i == n || j == m)
    {
        cout << 1 << nL;
        return;
    }

    string s_ = s.substr(i);
    string t_ = t.substr(j);

    if (n > m)
    {

        loop(k, i, n)
        {
            if (s[k] == t_[0])
            {
                if (s.substr(k) == t_)
                {
                    cout << 1 << nL;
                    return;
                }
            }
        }
    }
    else if (m > n)
    {
        loop(k, j, m)
        {
            if (t[k] == s_[0])
            {
                if (t.substr(k) == s_)
                {
                    cout << 1 << nL;
                    return;
                }
            }
        }
    }

    cout << 2 << nL;
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