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
    // n = s.size();
    int ans = n;
    int f = 0, fr = 0, fro = 0, fron = 0, front = 0;
    loop(i, 0, n)
    {
        if (s[i] == 'f')
        {
            f++;
        }
        else if (s[i] == 'r' && f > 0)
        {
            fr++;
            f--;
        }
        else if (s[i] == 'o' && fr > 0)
        {
            fro++;
            fr--;
        }
        else if (s[i] == 'n' && fro > 0)
        {
            fron++;
            fro--;
        }
        else if (s[i] == 't' && fron > 0)
        {
            front++;
            fron--;
        }
    }

    if (front > 0)
    {
        int tot = front;
        ans -= 4 * front;
        ans -= 4 * fron;
        ans -= 4 * min(max(tot - 1, 0ll), fro);
        tot -= min(tot - 1, fro);
        tot = max(tot, 0ll);
        ans -= 4 * min(max(tot - 2, 0ll), fr);
        tot -= min(tot - 2, fr);
        tot = max(tot, 0ll);
        ans -= 4 * min(max(tot - 3, 0ll), f);
        tot -= min(tot - 3, f);
        tot = max(tot, 0ll);
        ans += tot;
    }

    int k = 0, kc = 0, kca = 0, kcab = 0;

    reverse(all(s));

    loop(i, 0, n)
    {
        if (s[i] == 'k')
            k++;
        else if (s[i] == 'c' && k > 0)
            kc++, k--;
        else if (s[i] == 'a' && kc > 0)
            kca++, kc--;
        else if (s[i] == 'b' && kca > 0)
            kcab++, kca--;
    }

    if (kcab > 0)
    {
        int tot = kcab;
        ans -= 3 * kcab;
        ans -= 3 * kca;
        ans -= 3 * min(max(tot - 1, 0ll), kc);
        tot -= min(tot - 1, kc);
        tot = max(tot, 0ll);
        ans -= 3 * min(max(tot - 2, 0ll), k);
        tot -= min(tot - 2, k);
        tot = max(tot, 0ll);
        ans += tot;
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