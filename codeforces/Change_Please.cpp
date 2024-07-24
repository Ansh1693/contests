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
        int x;
        cin >> x;

        int y = 100 - x;
        y = y - y % 10;
        cout << y << endl;
    }
    return 0;
}