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
string s;
int q;
int n;
int a;
char b;
set<int> st;

void init()
{
    loop(i, 0, n)
    {
        if (s[i] == '1' && i + 3 < n)
        {
            if (s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                st.insert(i);
            }
        }
    }
}

void check(int pos, char ch)
{
    if (n < 4)
    {
        cout << "NO" << nL;
        return;
    }

    if (s[pos] == ch)
    {
        if (st.size() > 0)
        {
            cout << "YES" << nL;
            return;
        }
        else
        {
            cout << "NO" << nL;
            return;
        }
    }

    if (s[pos] == '0')
    {
        if (pos - 2 >= 0)
        {
            if (st.find(pos - 2) != st.end())
            {
                st.erase(pos - 2);
            }
        }

        if (pos - 3 >= 0)
        {
            if (st.find(pos - 3) != st.end())
            {
                st.erase(pos - 3);
            }
        }
    }
    else
    {
        if (pos - 1 >= 0)
        {
            if (st.find(pos - 1) != st.end())
            {
                st.erase(pos - 1);
            }
        }

        if (st.find(pos) != st.end())
        {
            st.erase(pos);
        }
    }

    if (ch == '0')
    {
        if (pos - 2 >= 0 && pos + 1 < n)
        {
            if (s[pos - 1] == '1' && s[pos - 2] == '1' && s[pos + 1] == '0')
            {
                st.insert(pos - 2);
            }
        }

        if (pos - 3 >= 0)
        {
            if (s[pos - 3] == '1' && s[pos - 2] == '1' && s[pos - 1] == '0')
            {
                st.insert(pos - 3);
            }
        }
    }
    else
    {
        if (pos - 1 >= 0 && pos + 2 < n)
        {
            if (s[pos - 1] == '1' && s[pos + 1] == '0' && s[pos + 2] == '0')
            {
                st.insert(pos - 1);
            }
        }

        if (pos + 3 < n)
        {
            if (s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0')
            {
                st.insert(pos);
            }
        }
    }

    s[pos] = ch;

    if (st.size() > 0)
    {
        cout << "YES" << nL;
        return;
    }
    else
    {
        cout << "NO" << nL;
        return;
    }
}

void solve()
{
    cin >> s;
    n = s.size();

    cin >> q;
    init();

    loop(i, 0, q)
    {
        cin >> a >> b;
        a--;
        check(a, b);
    }

    st.clear();
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