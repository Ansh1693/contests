#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    int i = 0;
    while (i < n - 1)
    {
        if (s[i + 1] != '0')
        {
            int s1 = stoi(s.substr(0, i + 1));
            int s2 = stoi(s.substr(i + 1, n - i - 1));

            if (s1 < s2)
            {
                cout << s1 << " " << s2 << endl;
                return;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    cout << "-1\n";
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