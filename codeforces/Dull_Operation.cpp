#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;

    for (int k = n - 50; k <= n; k += 2)
    {
        for (int l = n - 51; l < k; l += 2)
        {
            if (k >= 0 && l >= 0)
            {
                if ((k | l) * (k ^ l) == n)

                {
                    cout << k << " " << l << endl;
                    break;
                }
            }
        }
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