#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cout << i << " ";
    }

    for (int i = n; i > k; i--)
    {
        cout << i << " ";
    }

    cout << endl;
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