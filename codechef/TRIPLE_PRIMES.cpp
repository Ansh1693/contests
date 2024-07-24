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
const int mod = 1e10;

vector<int> find_p(int up)
{
    vector<bool> ch(up + 1, true);
    for (int num = 2; num * num <= up; ++num)
    {
        if (ch[num])
        {
            for (int multiple = num * num; multiple <= up; multiple += num)
            {
                ch[multiple] = false;
            }
        }
    }
    vector<int> ans;
    for (int num = 2; num <= up; ++num)
    {
        if (ch[num])
        {
            ans.push_back(num);
        }
    }
    return ans;
}

void solve(vector<int> &p)
{
    int z;
    cin >> z;

    if (z < 38)
    {
        cout << "No" << nL;
        return;
    }
    vector<int> eligible;
    for (auto &it : p)
    {
        int sq = it * it;
        if (sq < z)
        {
            eligible.push_back(sq);
        }
    }

    bool ch = false;

    int l, r;

    for (int i = 0; i < eligible.size(); i++)
    {
        l = 0;
        r = eligible.size() - 1;
        int mid = (l + r) / 2;
        while (l < r)
        {
            if (eligible[l] + eligible[r] + eligible[i] == z && l != i && r != i)
            {
                ch = true;
                break;
            }
            else if (eligible[l] + eligible[r] + eligible[i] < z)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        if (ch)
        {
            break;
        }
    }

    if (ch)
    {
        cout << "Yes" << nL;
        return;
    }

    cout << "No" << nL;
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
    vector<int> p = find_p(100000);
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve(p);
    }
    return 0;
}