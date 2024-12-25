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

// bool check(unordered_map<char, int> &mp, unordered_map<char, int> &rmp)
// {
//     if (mp['N'] / 2 != rmp['N'] || mp['S'] / 2 != rmp['S'] || mp['E'] / 2 != rmp['E'] || mp['W'] / 2 != rmp['W'])
//         return false;

//     // if (mp['N'] / 2 != hmp['N'] || mp['S'] / 2 != hmp['S'] || mp['E'] / 2 != hmp['E'] || mp['W'] / 2 != hmp['W'])
//     //     return false;

//     return true;
// }

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int y, x;
    y = 0, x = 0;
    unordered_map<char, int> mp;
    int fn = -1, fs = -1, fe = -1, fw = -1;

    loop(i, 0, n)
    {
        if (s[i] == 'N')
            y++, fn = i;
        if (s[i] == 'S')
            y--, fs = i;

        if (s[i] == 'E')
            x++, fe = i;
        if (s[i] == 'W')
            x--, fw = i;

        mp[s[i]]++;
    }

    if (x % 2 != 0 || y % 2 != 0)
    {
        cout << "NO\n";
        return;
    }

    if (n == 2 && x == 0 && y == 0)
    {
        cout << "NO\n";
        return;
    }

    string ans;
    loop(i, 0, n)
    {
        ans.pb('H');
    }

    if (x == 0 && y == 0)
    {
        if (fn != -1)
        {
            ans[fn] = 'R';
            ans[fs] = 'R';
        }
        else if (fe != -1)
        {
            ans[fe] = 'R';
            ans[fw] = 'R';
        }
    }
    else
    {
        loop(i, 0, n)
        {
            if (s[i] == 'N')
            {
                if (y > 0)
                {
                    ans[i] = 'R';
                    y -= 2;
                }
            }

            if (s[i] == 'S')
            {
                if (y < 0)
                {
                    ans[i] = 'R';
                    y += 2;
                }
            }

            if (s[i] == 'E')
            {
                if (x > 0)
                {
                    ans[i] = 'R';
                    x -= 2;
                }
            }

            if (s[i] == 'W')
            {
                if (x < 0)
                {
                    ans[i] = 'R';
                    x += 2;
                }
            }
        }
    }

    cout << ans << nL;
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