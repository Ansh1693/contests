#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int val(int x)
{
    if (x == 0)
        return 2;

    return 2 * val(x - 1) - 1;
}

int main()
{
    int n;
    cin >> n;
    int x = val(n);

    cout << x * x;
    return 0;
}