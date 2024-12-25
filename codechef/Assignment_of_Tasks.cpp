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
int n, m;
pii tasks[100005];
int skill[100005];
bool good(int mid)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int j = 0;
    loop(i, 0, n)
    {
        if (pq.empty())
        {
            pq.push({tasks[i].F + (tasks[i].S * skill[j]), j});
            j++;
        }
        else
        {
            pii x = pq.top();
            if (j < m)
            {
                // cout << i << " " << j << " " << (max(x.F, tasks[i].F) + (tasks[i].S * skill[x.S])) << " " << (tasks[i].F + (tasks[i].S * skill[j])) << nL;
                if ((max(x.F, tasks[i].F) + (tasks[i].S * skill[x.S])) < (tasks[i].F + (tasks[i].S * skill[j])))
                {
                    pq.pop();
                    pq.push({max(x.F, tasks[i].F) + (tasks[i].S * skill[x.S]), x.S});
                }
                else
                {
                    pq.push({tasks[i].F + (tasks[i].S * skill[j]), j});
                    j++;
                }
            }
            else
            {
                pq.pop();
                pq.push({x.F + (tasks[i].S * skill[x.S]), x.S});
            }
        }
    }

    int maxi = 0;

    while (!pq.empty())
    {
        pii x = pq.top();
        pq.pop();
        maxi = max(maxi, x.F);
    }

    return maxi <= mid;
}
void solve()
{
    cin >> n >> m;
    loop(i, 0, n) cin >> tasks[i].S;
    loop(i, 0, n) cin >> tasks[i].F;
    loop(i, 0, m) cin >> skill[i];

    sort(tasks, tasks + n);
    sort(skill, skill + m);

    // loop(i, 0, n)
    // {
    //     cout << tasks[i].F << " " << tasks[i].S << nL;
    // }

    int l = 0, r = 1e12;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (good(mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << nL;
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