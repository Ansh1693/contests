#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    vector<int> v(2 * n);

    for (int i = 0; i <= (2 * n) - 1; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int x = 0;
    int y = 0;

    for (int i = 0; i < n - 1; i++)
    {
        x += v[i + 1] - v[i];
        y += v[2 * n - 1 - i] - v[2 * n - 2 - i];
    }

    cout << x + y << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " " << v[2 * n - 1 - i] << endl;
    }
    // cout << endl;
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