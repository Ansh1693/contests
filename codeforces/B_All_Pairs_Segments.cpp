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
int a[100005];
int qu[100005];
void solve()
{
    cin >> n >> q;
    loop(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    map<int, int> mp;

    if (n % 2)
    {
        int curr = n - 1;
        int st = n - 1;
        loop(i, 0, n / 2)
        {
            mp[curr] = a[i + 1] - a[i];

            mp[curr]--;

            st -= 2;
            curr += st;
        }

        st = 0;

        loop(i, n / 2 + 1, n)
        {
            mp[curr] += a[i] - a[i - 1];

            mp[curr]--;

            st += 2;
            curr -= st;
        }

        curr = n - 1;

        st = n - 2;
        loop(i, 0, n / 2)
        {
            mp[curr] += 1;
            curr += st;
            st -= 2;
        }

        st = 1;

        loop(i, n / 2, n)
        {
            mp[curr] += 1;
            curr -= st;
            st += 2;
        }
    }
    else
    {
        int curr = n - 1;
        int st = n - 1;
        loop(i, 0, n / 2)
        {
            mp[curr] = a[i + 1] - a[i];

            mp[curr]--;

            st -= 2;
            curr += st;
        }

        st = 1;

        loop(i, n / 2 + 1, n)
        {
            mp[curr] += a[i] - a[i - 1];

            mp[curr]--;

            st += 2;
            curr -= st;
        }

        curr = n - 1;
        st = n - 2;
        loop(i, 0, n / 2)
        {
            mp[curr] += 1;
            curr += st;
            st -= 2;
        }

        st = 2;

        loop(i, n / 2, n)
        {
            mp[curr] += 1;
            curr -= st;
            st += 2;
        }
    }

    // loop(i, 0, n)
    // {
    //     loop(j, i + 1, n)
    //     {
    //         qu[a[i]]++;
    //         qu[a[j] + 1]--;
    //     }
    // }

    // loop(i, a[0], a[n - 1] + 1)
    // {
    //     qu[i] += qu[i - 1];
    // }

    // loop(i, a[0], a[n - 1] + 1)
    // {
    //     cout << qu[i] << " ";
    // }

    // cout << nL;
    int x;
    loop(i, 0, q)
    {
        cin >> x;

        // cout << x << ": " << mp[x] << nL;

        cout << mp[x] << " ";
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