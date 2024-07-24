#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int n, k;
vector<int> arr;

bool good(ld x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += floor(arr[i] / x);
    }
    return cnt >= k;
}

int main()
{
    cin >> n >> k;

    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ld l = 0, r = 1e8;
    for (int i = 0; i < 100; i++)
    {
        ld m = (l + r) / 2;
        if (good(m))
            l = m;
        else
            r = m;
    }

    cout << setprecision(20) << l << endl;

    return 0;
}