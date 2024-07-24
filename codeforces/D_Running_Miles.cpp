#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
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
    vi arr(n);
    loop(i, 0, n)
    {
        cin >> arr[i];
    }

    vi prefix(n),
        suffix(n);

    loop(i, 0, n)
    {
        prefix[i] = arr[i] + i;
        suffix[i] = arr[i] - i;
    }

    loop(i, 1, n)
    {
        prefix[i] = max(prefix[i - 1], prefix[i]);
    }

    rloop(i, 0, n - 1)
    {
        suffix[i] = max(suffix[i + 1], suffix[i]);
    }

    int maxi = 0;

    loop(i, 1, n - 1)
    {
        maxi = max(maxi, prefix[i - 1] + suffix[i + 1] + arr[i]);
    }

    cout << maxi << nL;
}
signed main()
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}