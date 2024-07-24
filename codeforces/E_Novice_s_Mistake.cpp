// https://codeforces.com/contest/1992/problem/E

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

string ntimes(string n, int times)
{
    string ans = "";
    for (int i = 0; i < times; i++)
    {
        ans += n;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int len = to_string(n).length();
    string s = ntimes(to_string(n), 10000);

    cout << s << nL;

    int a = 1;

    vector<pii> ans;

    while (a < 10000)
    {
        for (int b = 1; b < a * len; b++)
        {
            int res = (len * a) - b;
            int sum = (n * a) - b;
            if ((len * a) - b == to_string(sum).size())
            {
                if (stoll(s.substr(0, res)) == sum)
                {
                    ans.pb({a, b});
                }
            }
        }
    }

    cout << ans.size() << nL;
    for (auto x : ans)
    {
        cout << x.F << " " << x.S << nL;
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