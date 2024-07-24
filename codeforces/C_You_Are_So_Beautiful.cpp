#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

vector<int> arr;

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}