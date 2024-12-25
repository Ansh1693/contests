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
int n, k;
int a[N];

void solve()
{
    cin >> n >> k;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int k1 = k;
    loop(i, 1, n + 1)
    {
        cin >> a[i];

        if (pq.size() < k1)
        {
            pq.push({a[i], i});
        }
        else
        {
            if (a[i] > pq.top().F)
            {
                pq.pop();
                pq.push({a[i], i});
            }
        }
    }

    int ans = 0;
    int mini = pq.top().S;
    int maxi = pq.top().S;

    while (!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        ans += 2 * p.F;
        mini = min(mini, p.S);
        maxi = max(maxi, p.S);
    }

    ans -= a[mini] - a[maxi];

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