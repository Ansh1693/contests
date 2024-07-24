// https://www.codechef.com/START142B/problems/LENGTHX

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

int addString(string a, string b)
{
    string ans = "";
    int n = a.size();
    int m = b.size();
    if (m > n)
        return addString(b, a);

    int carry = 0;

    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
    {
        int dA = a[i] - '0';
        int dB = b[j] - '0';

        dA += dB + carry;

        if (dA >= 10)
        {
            dA = dA % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ans.push_back(dA + '0');
        i--;
        j--;
    }

    while (i >= 0)
    {
        int dA = a[i] - '0';
        dA += carry;

        if (dA >= 10)
        {
            dA = dA % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ans.push_back(dA + '0');
        i--;
    }

    if (carry > 0)
    {
        ans.push_back(carry + '0');
    }

    // reverse(ans.begin(), ans.end());
    // cout << ans << endl;
    return ans.size();
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    vector<set<int>> mp;
    for (int i = n - 1; i >= 0; i++)
    {
        if (i + 1 < n)
        {
            mp[i] = mp[i + 1];
        }

        mp[i].insert(a[i]);
    }

    int ans = 0;

    loop(i, 0, n - 1)
    {
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