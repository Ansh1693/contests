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
int l, r;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

class SegmentTree
{
private:
    vector<int> tree;
    int size;

    void buildTree(const vector<int> &arr, int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int queryTree(int start, int end, int l, int r, int node)
    {
        if (r < start || l > end)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftGCD = queryTree(start, mid, l, r, 2 * node + 1);
        int rightGCD = queryTree(mid + 1, end, l, r, 2 * node + 2);
        return gcd(leftGCD, rightGCD);
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        size = arr.size();
        tree.resize(4 * size);
        buildTree(arr, 0, size - 1, 0);
    }

    int query(int l, int r)
    {
        return queryTree(0, size - 1, l, r, 0);
    }
};

void solve()
{
    cin >> n >> q;
    loop(i, 0, n) cin >> a[i];

    if (n == 1)
    {
        while (q--)
        {
            cin >> l >> r;
            cout << 0 << " ";
        }
        cout << nL;
        return;
    }

    vi diff(n - 1);

    loop(i, 0, n - 1)
    {
        diff[i] = abs(a[i] - a[i + 1]);
    }

    SegmentTree st(diff);

    while (q--)
    {
        cin >> l >> r;
        l--, r--;

        if (l == r)
            cout << 0 << " ";
        else
            cout << st.query(l, r - 1) << " ";
    }

    cout << nL;
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