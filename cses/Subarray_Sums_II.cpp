#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    int n, t;
    cin >> n >> t;
    vector<ll> arr(n + 1, 0);
    map<ll, ll> mp;
    mp[0]++;
    int x;
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        arr[i] = arr[i - 1] + x;
        cnt += mp[arr[i] - t];
        mp[arr[i]]++;
    }

    cout << cnt;

    return 0;
}