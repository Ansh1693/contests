#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nL "\n"
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; i++)

typedef vector<int> vi;

const int mod = 1e9 + 7;
const int MAXN = 200005;

int n, l, r;
int a[MAXN];

bool hasDuplicate(const vi &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            return true;
        }
    }
    return false;
}

bool isProductInRange(const vi &arr, int l, int r)
{
    int pro = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            pro *= (arr[i] ^ arr[j]);
            if (pro > r)
                return false;
        }
        if (pro > r)
            return false;
    }
    return pro >= l && pro <= r;
}

void solve()
{
    cin >> n >> l >> r;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    sort(all(a));

    if (hasDuplicate(a))
    {
        cout << (l == 0 ? "YES" : "NO") << nL;
        return;
    }

    if (n < 14 && isProductInRange(a, l, r))
    {
        cout << "YES" << nL;
    }
    else
    {
        cout << "NO" << nL;
    }
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
