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

    bool ch = false;

    if (s[0] >= 'a' && s[0] <= 'z')
    {
        ch = true;
    }
    else if (s[0] < 'a' || s[0] > 'z')
    {
        cout << "NO" << nL;
        return;
    }
    int i = 1;
    while (i < n)
    {
        if (ch && s[i] >= '0' && s[i] <= '9')
        {
            cout << "NO" << nL;
            return;
        }
        else if (!ch && s[i] >= '0' && s[i] <= '9')
        {
            if (s[i] >= s[i - 1])
            {
                i++;
            }
            else
            {
                cout << "NO" << nL;
                return;
            }
        }
        else if (!ch && (s[i] >= 'a' && s[i] <= 'z'))
        {
            ch = true;
            i++;
        }
        else if (ch && (s[i] >= 'a' || s[i] <= 'z'))
        {
            if (s[i] >= s[i - 1])
            {
                i++;
            }
            else
            {
                cout << "NO" << nL;
                return;
            }
        }
        else
        {
            cout << "NO" << nL;
            return;
        }
    }

    cout << "YES" << nL;
    return;
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