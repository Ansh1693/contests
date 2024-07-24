#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    if (mp.size() > 2)
    {
        cout << "No" << endl;
        return;
    }

    int val1 = -1, val2 = -1;

    for (auto x : mp)
    {
        if (val1 == -1)
        {
            val1 = x.second;
        }
        else
        {
            val2 = x.second;
        }
    }

    if (val2 == -1)
    {
        cout << "Yes" << endl;
        return;
    }

    if (val1 == val2)
    {
        cout << "Yes" << endl;
        return;
    }

    if (n % 2 && abs(val1 - val2) == 1)
    {
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
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