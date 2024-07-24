#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    int sm = 0;
    int odd = -1;

    bool check = true;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sm += arr[i];

        if (odd != -1)
        {
            if (odd != arr[i] % 2)
            {
                check = false;
            }
        }
        else
        {
            odd = arr[i] % 2;
        }
    }

    if (!check || sm % n)
    {
        cout << "No\n";
        return;
    }
    sm = sm / n;

    for (int i = 0; i < n; i++)
    {
        int diff = abs(arr[i] - sm);

        if (diff % 2)
        {
            check = false;

            break;
        }
    }

    if (!check)
    {
        cout << "No\n";
        return;
    }
    else
    {

        cout << "Yes\n";
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