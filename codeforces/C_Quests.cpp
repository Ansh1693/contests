#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }

    vector<int> b(n);

    for (int &i : b)
    {
        cin >> i;
    }

    int sum = 0;

    int quest = 0;

    int maxb = 0;

    for (int i = 0; i < n; i++)
    {
        if (k == i)
            break;

        maxb = max(maxb, b[i]);
        sum += a[i];

        quest = max(sum + (k - i - 1) * maxb, quest);
    }

    cout << quest << endl;
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