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
    vector<pii> arr(n);
    loop(i, 0, n)
    {
        cin >> arr[i].F >> arr[i].S;
    }

    sort(all(arr));

    unordered_map<int, int> reduced_x;
    for (int c = 0; c < n; c++)
    {
        reduced_x[arr[c].first] = c;
    }

    auto cmp = [&](const pair<int, int> &c1, const pair<int, int> &c2)
    {
        return c1.second < c2.second;
    };
    sort(arr.begin(), arr.end(), cmp);
    unordered_map<int, int> reduced_y;
    for (int c = 0; c < n; c++)
    {
        reduced_y[arr[c].second] = c;
    }

    for (auto &[x, y] : arr)
    {
        x = reduced_x[x];
        y = reduced_y[y];
    }
    sort(all(arr));

    vector<vector<int>> lt_y(n, vector<int>(n + 1));
    vector<vector<int>> gt_y(n, vector<int>(n + 1));
    for (int c = 0; c < n; c++)
    {
        int curr_y = arr[c].second;
        for (int x = 1; x <= n; x++)
        {
            lt_y[curr_y][x] =
                (lt_y[curr_y][x - 1] + (arr[x - 1].second < curr_y));
            gt_y[curr_y][x] =
                (gt_y[curr_y][x - 1] + (arr[x - 1].second > curr_y));
        }
    }

    int total = 0;
    for (int c1 = 0; c1 < n; c1++)
    {
        for (int c2 = c1 + 1; c2 < n; c2++)
        {
            int bottom = min(arr[c1].second, arr[c2].second);
            int top = max(arr[c1].second, arr[c2].second);

            int bottom_total = 1 + lt_y[bottom][c2 + 1] - lt_y[bottom][c1];
            int top_total = 1 + gt_y[top][c2 + 1] - gt_y[top][c1];
            total += (long long)bottom_total * top_total;
        }
    }

    total += n + 1;

    cout << total << endl;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}