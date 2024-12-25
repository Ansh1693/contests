#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define PI 3.1415926535897932384626
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
// pii v[200005];

// void make_set(int x)
// {
//     v[x].first = x;
//     v[x].second = 0; // rank
// }

// int find_set(int x)
// {
//     if (v[x].first != x)
//     {
//         v[x].first = find_set(v[x].first);
//     }
//     return v[x].first;
// }

// void union_set(int x, int y)
// {
//     int xx = find_set(x);
//     int yy = find_set(y);
//     if (xx == yy)
//         return;

//     // mp.erase(xx);
//     // mp.erase(yy);

//     if (v[xx].second < v[yy].second)
//     {
//         v[xx].first = yy;
//     }
//     else if (v[xx].second > v[yy].second)
//     {
//         v[yy].first = xx;
//     }
//     else
//     {
//         v[yy].first = xx;
//         v[xx].second++;
//     }
// }

// bool vis[200005];
// vi adj[200005];

// void dfs(int nd)
// {
//     vis[nd] = true;
//     for (auto x : adj[nd])
//     {
//         if (!vis[x])
//         {
//             dfs(x);
//         }
//     }
// }

void solve()
{
    int n, m;
    cin >> n >> m;
    vi cnt(m);

    vvi vis(n);

    loop(i, 0, m)
    {
        int a, d, k;
        cin >> a >> d >> k;
        a--;
        int maxi = n - a;
        maxi /= d;

        k = min(k, maxi);

        loop(j, 0, k + 1)
        {
            if (a + j * d < n)
            {
                cnt[i]++;
                vis[a + j * d].push_back(i);
            }
        }
    }

    int ans = n;

    vector<bool> viss(m, 0);
    loop(i, 0, n)
    {
        if (vis[i].size() == 1 && !viss[vis[i][0]])
        {

            viss[vis[i][0]] = 1;
            ans -= cnt[vis[i][0]];
            ans++;
        }
        else
        {
            bool ch = true;
            for (auto x : vis[i])
            {
                if (viss[x])
                {
                    ans--;
                }
                else
                {
                    viss[x] = 1;
                    ans -= cnt[x];
                    ch = false;
                }
            }
            if (!ch)
                ans++;
                }
    }
    cout << ans << nL;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
