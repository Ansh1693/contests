#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
// https://www.codechef.com/START105D/problems/MAJIK

void solve()
{
    int n;
    cin >> n;
    int p, q;
    cin >> p >> q;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int ans = arr[n - 1] - arr[0];

    vector<int> brr(n - 2);

    for (int i = 1; i < n - 1; i++)
    {
        brr[i - 1] = abs(arr[i]);
    }

    sort(brr.begin(), brr.end());

    for (int i = 0; i < min(p + q, n - 2); i++)
    {
        ans += brr[n - 2 - i - 1];
    }
    cout << ans << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}