#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll sum = 0;
        unordered_map<ll, ll> mp;
        mp[0]++;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += (s[i] - '0');
            ll x = sum - i - 1;
            mp[x]++;
            cnt += mp[x] - 1;
        }

        cout << cnt << "\n";
    }
    return 0;
}