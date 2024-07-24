#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    char a;
    vector<int> v(26, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v[a - 'A']++;
        if (v[a - 'A'] == 1 + (a - 'A'))
        {
            count++;
        }
    }

    cout << count << endl;
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