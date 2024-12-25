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
int n;

void solve()
{
    cin >> n;
    vector<unordered_set<int>> a(n);
    loop(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].insert(y);
        a[y].insert(x);
    }
    int ans = 0;
    loop(i, 0, n)
    {
        ans = max(ans, (int)a[i].size());
    }
    vvi res(ans,vi(n,-1));
    vi order;
    vi vis(n,0);

    function<void(int,int)> dfs = [&](int x,int p){
        vis[x] = 1;
        order.pb(x);
        for(auto y : a[x]){
            if(y == p) continue;
            if(!vis[y]){
                dfs(y,x);
            }
        }
    };

    loop(i,0,n){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    unordered_set<int> s;

    loop(i,1,ans+1){
        int c = 1;
        for(auto x : order){
            if(res[i-1][x] != -1) continue;
            s = a[x];
            for(auto y: s){
                if(res[i-1][x] == -1 && res[i-1][y] == -1){
                    res[i-1][x] = c;
                    res[i-1][y] = c;
                    c++;
                    a[x].erase(y);
                    a[y].erase(x);

                    // cout<<x<<" "<<y<<nL;
                }
            }
        }

        loop(j,0,n){
            if(res[i-1][j] == -1){
                res[i-1][j] = c;
                c++;
            }
        }
    }

    cout << ans << nL;
    for (auto v : res)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << nL;
    }
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