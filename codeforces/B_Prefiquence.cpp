#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a;
        cin >> b;
        int maxi = 0, j = 0;

        for (int i = 0; i < m && j < n; i++)
        {
            if (b[i] == a[j])
            {
                maxi++;
                j++;
            }
        }

        cout << maxi << endl;
    }
    return 0;
}