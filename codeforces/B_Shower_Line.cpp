#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int g[5][5];
int main()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int j[5], ans[5], temp, maxi = 0;

    for (int i = 0; i < n; i++)
    {
        j[i] = i;
    }

    do
    {
        temp = g[j[0]][j[1]] + g[j[1]][j[0]];
        temp += g[j[2]][j[3]] + g[j[3]][j[2]];

        temp += g[j[1]][j[2]] + g[j[2]][j[1]];
        temp += g[j[3]][j[4]] + g[j[4]][j[3]];

        temp += g[j[2]][j[3]] + g[j[3]][j[2]];

        temp += g[j[3]][j[4]] + g[j[4]][j[3]];

        if (temp > maxi)
        {
            maxi = temp;
            for (int i = 0; i < n; i++)
            {
                ans[i] = j[i];
            }
        }

    } while (next_permutation(j, j + n));

    cout << maxi;

    return 0;
}