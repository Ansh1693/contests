#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    int x, y;
    cin >> x >> y;
    if (y >= 2 * x)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}