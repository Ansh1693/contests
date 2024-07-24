#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n, vector<int> &a)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (a[n] != -1)
    {
        return a[n];
    }

    a[n] = 0;

    for (int i = 1; i < 7; i++)
    {
        a[n] = (a[n] + solve(n - i, a)) % 1000000007;
    }

    return a[n];
}

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);

    cout << solve(n, a) << endl;
    return 0;
}