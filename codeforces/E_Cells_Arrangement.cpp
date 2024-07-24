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
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << "1 1\n";
            cout << "1 2\n";
        }
        else if (n == 3)
        {
            cout << "2 1\n";
            cout << "2 3\n";
            cout << "3 1\n";
        }
        else
        {
            for (int i = 1; i <= n - 2; i++)
            {
                cout << "1 " << i << endl;
            }

            cout << n << " 2\n";
            cout << n << " " << n << endl;
        }

        cout << endl;
    }
    return 0;
}