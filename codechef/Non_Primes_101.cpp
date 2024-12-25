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
const int N = 2e5 + 5;
int n;
int a[N];
int cnt[101];
vector<bool> prime;

void solve()
{
    cin >> n;
    memset(cnt, -1, sizeof(cnt));
    pii ans = {-1, -1};
    loop(i, 0, n)
    {
        cin >> a[i];
        if (ans.F == -1)
        {
            loop(j, 1, 101)
            {
                if (cnt[j] != -1)
                {
                    if (!prime[a[i] + j])
                    {
                        ans = {cnt[j], i};
                        break;
                    }
                }
            }
        }

        cnt[a[i]] = i;
    }

    if (ans.F == -1)
        cout << "-1" << nL;
    else
    {
        cout << ans.F + 1 << " " << ans.S + 1 << nL;
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

    int n = 200;
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}