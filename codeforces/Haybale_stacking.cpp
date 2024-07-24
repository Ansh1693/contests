#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1, 0);
    ll a, b;
    for (ll i = 0; i < k; i++)
    {
        cin >> a >> b;
        arr[a]++;
        if (b + 1 <= n)
        {
            arr[b + 1]--;
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }

    vector<ll> ans(arr.begin() + 1, arr.end());
    sort(ans.begin(), ans.end());

    // for (auto &it : ans)
    // {
    //     cout << it << ' ';
    // }
    // cout << "\n";

    cout << ans[n / 2];
    return 0;
}