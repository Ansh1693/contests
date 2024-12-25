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
const int N = 1e7 + 10;
int gcddd[N];

int n;

int a[N];

void solve()
{
    cin >> n;
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    int x = 0;

    loop(i, 0, n)
    {
        x ^= gcddd[a[i]];
    }

    cout << (x == 0 ? "Bob" : "Alice") << nL;
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    // #endif

    memset(gcddd, -1, sizeof(gcddd));
    gcddd[0] = 0;
    gcddd[1] = 1;
    int cnt = 0;
    for (int i = 2; i < N; i++)
    {
        if (gcddd[i] == -1)
        {
            cnt++;
            if (i == 2)
                cnt = 0;
            if (i == 3)
                cnt = 2;
            for (long long j = i; j < N; j += i)
            {
                if (gcddd[j] == -1)
                    gcddd[j] = cnt;
            }
        }
        if (gcddd[i] == -1)
        {
            cnt++;
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