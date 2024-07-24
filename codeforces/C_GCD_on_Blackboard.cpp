#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> L(n + 1, 0);
    vector<ll> R(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        L[i + 1] = gcd(arr[i], L[i]);
        R[n - i - 1] = gcd(arr[n - i - 1], R[n - i]);
    }

    vector<ll> M(n, 0);
    ll maxi = 0;

    for (ll i = 0; i < n; i++)
    {
        M[i] = gcd(L[i], R[i + 1]);
        maxi = max(M[i], maxi);
    }

    cout << maxi;

    return 0;
}
