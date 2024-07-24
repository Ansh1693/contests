#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    ll mini = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mini == -1)
        {
            mini = a[i];
        }
        else
        {
            mini = min(mini, a[i]);
        }
        mp[a[i]]++;
    }

    if (mp[mini] == n)

    {
        cout << "NO\n";
        return;
    }

    if (mp[mini] == 1)
    {
        cout << "YES\n";
        return;
    }

    int check = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != mini)
        {
            if (a[i] % mini != 0)
            {
                check = 1;
                break;
            }
        }
    }

    if (check)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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
