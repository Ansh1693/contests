#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);

    vector<int> odd;
    vector<int> even;
    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        if (x.size() % 2 == 0)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
    }

    int ans = n;
    for (int i = 0; i < odd.size(); i++)
    {
        for (int j = i + 1; j < odd.size(); j++)
        {
            if (i == j || a[odd[i]] == a[odd[j]])
            {
                ans += 2;
                continue;
            }

            int x = 0;
            int y = a[odd[i]].size() + a[odd[j]].size() - 1;
            string s = a[odd[i]] + a[odd[j]];
            string s1 = a[odd[j]] + a[odd[i]];

            int sum = 0;
            int sum1 = 0;
            while (x < y)
            {
                sum += s[x] - '0';
                sum -= s[y] - '0';
                sum1 += s1[x] - '0';
                sum1 -= s1[y] - '0';
                x++;
                y--;
            }

            if (sum == 0)
            {
                ans++;
            }

            if (sum1 == 0)
            {
                ans++;
            }
        }
    }

    for (int i = 0; i < even.size(); i++)
    {
        for (int j = i + 1; j < even.size(); j++)
        {
            if (i == j || a[even[i]] == a[even[j]])
            {
                ans += 2;
                continue;
            }

            int x = 0;
            int y = a[even[i]].size() + a[even[j]].size() - 1;
            string s = a[even[i]] + a[even[j]];
            string s1 = a[even[j]] + a[even[i]];

            int sum = 0;
            int sum1 = 0;
            while (x < y)
            {
                sum += s[x] - '0';
                sum -= s[y] - '0';
                sum1 += s1[x] - '0';
                sum1 -= s1[y] - '0';
                x++;
                y--;
            }

            if (sum == 0)
            {
                ans++;
            }
            if (sum1 == 0)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main()
{

    solve();

    return 0;
}