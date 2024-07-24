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

const int mod = 1000002;

vi p;
vi s(mod, 0);

const int MAX_K = 1000000;

umii mp;

void helper()
{
    s[1] = 1;
    for (int i = 2; i < mod; ++i)
    {
        if (s[i] == 0)
        {
            s[i] = i;
            for (int j = i * i; j < mod; j += i)
            {
                if (s[j] == 0)
                {
                    s[j] = i;
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    int ans = 0;

    if (s[n] == n)
    {
        for (int it : p)
        {
            if (it > n)
                break;
            ans += (long long)it * n;
        }
    }
    else
    {
        for (int it : p)
        {
            if (it > s[n])
                break;
            ans += (long long)it * n;
        }
    }

    cout << ans << endl;
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
    helper();
    for (int i = 2; i < mod; ++i)
    {
        if (s[i] == i)
        {
            p.push_back(i);
        }
    }

    vi a(tc);
    int maxi = -1;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}