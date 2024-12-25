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
string s;

void solve()
{
    cin >> n >> s;
    string p1 = "", p2 = "";

    loop(i, 0, n)
    {
        p1 += (i % 2 == 0) ? '0' : '1';
        p2 += (i % 2 == 0) ? '1' : '0';
    }

    vi c1, c2;
    loop(i, 0, n)
    {
        if (s[i] != p1[i])
        {
            c1.pb(i);
        }
        if (s[i] != p2[i])
        {
            c2.pb(i);
        }
    }

    if (c1.empty() || c2.empty())
    {
        cout << "Yes" << nL;

        return;
    }

    auto checkString = [&](const string &temp)
    {
        loop(i, 1, n)
        {
            if (temp[i] == temp[i - 1])
                return false;
        }

        // cout << temp << nL;
        return true;
    };

    auto check = [&](const vector<int> &c)
    {
        int l = c.front(), r = c.back();

        string temp = s;
        while (l < r)
            swap(temp[l++], temp[r--]);

        return checkString(temp);
    };

    if (check(c1) || check(c2))
    {
        cout << "Yes" << nL;
        return;
    }

    cout << "No" << nL;
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