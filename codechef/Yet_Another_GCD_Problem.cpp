#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int k)
{
    vector<int> ans;
    if (n == 1 && k == 1)
    {
        ans.push_back(-1);
        // continue;
    }
    else if (k >= n)
    {
        for (int i = 1; i < n; i++)
        {
            // cout << i + 1 << " ";

            ans.push_back(i + 1);
        }

        ans.push_back(1);

        // continue;
    }
    else
    {

        for (int i = k; i <= n; i++)
        {
            ans.push_back(i);
        }

        for (int i = 1; i < k; i++)
            ans.push_back(i);
    }

    // cout << endl;

    return ans;
}

void check(vector<int> &a, int n, int k)
{
    if (a.back() == -1)
    {
        cout << -1 << endl;
        return;
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;

        if (mp[a[i]] > 1)
        {
            cout << "False" << endl;
            for (auto it : a)
            {
                cout << it << " ";
            }
            cout << endl;

            return;
        }
        if (a[i] % k == i + 1)
        {
            cout << "False" << endl;
            for (auto it : a)
            {
                cout << it << " ";
            }
            cout << endl;

            return;
        }
    }

    cout << true << endl;
}

int main()
{
    // your code goes here
    // freopen("div7.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<int> a;
    for (int n = 1; n <= 100; n++)
    {
        for (int k = 1; k <= n; k++)
        {
            a = solve(n, k);
            cout << n << " " << k << ":";
            check(a, n, k);
        }
    }
}
