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

// bool checkLoneliness(const vector<int> &a, int k)
// {
//     int n = a.size();
//     vector<int> subarray_or(n - k + 1, 0);

//     for (int i = 1; i <= k; ++i)
//     {
//         subarray_or[0] |= a[i - 1];
//     }

//     int i = 1;
//     int cur = subarray_or[0];

//     while (i <= n - k)
//     {
//         cur = cur & ~a[i - 1];
//         cur = cur | a[i + k - 1];
//         subarray_or[i] = cur;
//         i++;
//     }

//     for (int i = 1; i <= n - k; ++i)
//     {
//         if (subarray_or[i] != subarray_or[0])
//         {
//             return false;
//         }
//     }
//     return true;
// }

bool checkLoneliness(const vector<int> &a, int k)
{
    int n = a.size();
    for (int i = 0; i <= n - k; ++i)
    {
        int or_value = 0;
        for (int j = i; j < i + k; ++j)
        {
            or_value |= a[j];
        }
        if (i > 0 && or_value != a[i - 1])
        {
            return false;
        }
    }
    return true;
}

int findLoneliness(const vector<int> &a)
{
    int n = a.size();

    for (int i = 1; i <= n; ++i)
    {
        if (checkLoneliness(a, i))
        {
            return i;
        }
    }

    return n;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    cout << findLoneliness(a) << nL;
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