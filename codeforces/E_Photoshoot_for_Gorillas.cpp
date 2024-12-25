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

int n, m, k;
int w;
int gorilla[N];

void solve()
{
    cin >> n >> m >> k;
    priority_queue<int, vi, greater<int>> pq;
    cin >> w;
    loop(i, 0, w)
    {
        cin >> gorilla[i];
    }

    sort(gorilla, gorilla + w);

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            int a = max(i - k + 2, 1LL);
            int b = max(j - k + 2, 1LL);
            int c = min(i + 1, n - k + 1);
            int d = min(j + 1, m - k + 1);

            int x = (c - a + 1) * (d - b + 1);

            if (pq.size() < w)
            {
                pq.push(x);
            }
            else
            {
                if (x > pq.top())
                {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }

    // deb2(n, m);
    // deb2(k, w);

    int ans = 0;
    int i = 0;
    while (!pq.empty())
    {
        ans += pq.top() * gorilla[i];
        i++;
        pq.pop();
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