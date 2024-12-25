// I intend to live life, not just exist...
// Aeron
#include <bits/stdc++.h>
using namespace std;
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i, x, n) for (int i = x; i < n; i++)
#define fr(i, k, n) for (int i = k; i >= n; i--)
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
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
typedef map<int, int> mii;
const int mod = 1e9 + 7;

vvi moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

int n, m, k;
string s;
int res = 0;

void dfs(int pos, string curr)
{

    if (m != 0 && curr.find(s) != string::npos)
    {
        return;
    }

    if (curr.size() == n)
    {
        res = (res + 1) % mod;
        return;
    }
    for (int nextPos : moves[pos])
    {
        curr.push_back(nextPos + '0');
        dfs(nextPos, curr);
        curr.pop_back();
    }
}

void solution()
{
    cin >> n >> m >> k;
    cin >> s;
    dfs(k, "");
    cout << res % mod;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solution();
        cout << endl;
    }
}
