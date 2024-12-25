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
int n, q;
int a[200005];
string s;
int x;

void solve()
{
    cin >> n >> q;
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    cin >> s;

    set<int> st;

    vi lefty(n, 0);
    vi righty(n, 0);
    lefty[0] = a[0];

    loop(i, 1, n)
    {
        lefty[i] = max(lefty[i - 1], a[i]);
    }

    righty[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        righty[i] = min(righty[i + 1], a[i]);
    }
    loop(i, 1, n)
    {
        if (s[i - 1] == 'L' && s[i] == 'R')
        {
            if (lefty[i - 1] > righty[i])
                st.insert(i);
        }
    }
    while (q--)
    {
        cin >> x;
        x--;

        if (s[x] == 'L')
        {
            if (s[x + 1] == 'R')
                st.erase(x + 1);
            s[x] = 'R';

            if (s[x - 1] == 'L' && lefty[x - 1] > righty[x])
                st.insert(x);
        }
        else
        {
            if (s[x - 1] == 'L')
                st.erase(x);
            s[x] = 'L';

            if (s[x + 1] == 'R' && lefty[x] > righty[x + 1])
                st.insert(x + 1);
        }
        // bool ch = 0;
        // for (auto i : st)
        // {
        //     if (lefty[i - 1] > righty[i])
        //     {
        //         ch = 1;
        //     }

        //     break;
        // }

        if (st.size() > 0)
        {
            cout << "NO" << nL;
        }
        else
        {
            cout << "YES" << nL;
        }
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