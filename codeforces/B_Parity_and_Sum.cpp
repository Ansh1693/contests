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
    // priority_queue<int> odd;
    // priority_queue<int> even;
    // int x;
    // loop(i, 0, n)
    // {
    //     cin >> x;
    //     if (x % 2 == 0)
    //         even.push(x);
    //     else
    //         odd.push(x);
    // }

    // if (even.size() == n || odd.size() == n)
    // {
    //     cout << 0 << nL;
    //     return;
    // }

    // int ans = 0;

    // while (odd.empty() == false && even.empty() == false)
    // {
    //     if (odd.top() <= even.top())
    //     {
    //         int tot = odd.top() + even.top();
    //         odd.pop();
    //         odd.push(tot);
    //     }
    //     else
    //     {
    //         int tot = odd.top() + even.top();
    //         odd.pop();
    //         even.pop();
    //         odd.push(tot);
    //     }
    //     ans++;
    // }

    // cout << ans << nL;

    vi odd, even;

    int x;
    loop(i, 0, n)
    {
        cin >> x;
        if (x % 2 == 0)
            even.pb(x);
        else
            odd.pb(x);
    }

    if (even.size() == n || odd.size() == n)
    {
        cout << 0 << nL;
        return;
    }

    sortall(odd);
    sortall(even);

    int ans = 0;
    int ele = odd.back();
    int i = 0;
    for (; i < even.size(); i++)
    {
        if (even[i] >= ele)
        {
            while (ele <= even[i])
            {
                ele += even.back();
                ans++;
            }

            i--;
        }
        else
        {
            ans++;
            ele += even[i];
        }
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