#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> rem(n - 1);
        int maxi = -1;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> rem[i];

            maxi = max(maxi, rem[i]);
        }

        vector<int> ans(n);

        ans[0] = maxi + 1 > 2 ? maxi + 1 : maxi + 2;
        int last = ans[0];

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] + rem[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}