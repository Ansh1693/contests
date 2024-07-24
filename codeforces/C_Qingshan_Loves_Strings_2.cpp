#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;

    string s = s1;
    // cout << n << " " << s << endl;

    if (n % 2 == 1)
    {

        cout << "-1" << endl;
        return;
    }
    int i = 0, j = n - 1;

    int cnt = 0;
    vector<int> v;

    // cout << s << endl;

    string t = "01";

    while (i < j)
    {

        if (cnt > 300)
        {
            cout << "-1" << endl;
            return;
        }

        if (s[i] == s[j] && s[i] == '0')
        {
            s.insert(j + 1, t);
            cnt++;
            v.push_back(j + 1);

            j += 2;
        }
        else if (s[i] == s[j] && s[i] == '1')
        {
            if (i == 0)
            {
                s = t + s;
                cnt++;
                v.push_back(0);
            }
            else
            {
                s.insert(i, t);
                cnt++;
                v.push_back(i);
            }

            j += 2;
        }

        // cout << i << " " << j << " " << s << endl;

        i++;
        j--;
    }

    if (cnt > 300)
    {
        cout << "-1" << endl;
        return;
    }
    cout << cnt << endl;
    for (auto x : v)
        cout << x << " ";
    cout << endl;
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

// #include <bits/stdc++.h>
// using namespace std;

// void solve(int n, string &s)
// {
//     int i = 0, j = n - 1, posCnt = 0;
//     bool flag = true;
//     vector<int> pos;
//     while (i < j)
//     {
//         if (posCnt > 300)
//         {
//             cout << "-1" << endl;
//             return;
//         }
//         if (s[i] == s[j])
//         {
//             if (s[i] == '1' || s[j] == '0')
//             {
//                 cout << "-1" << endl;
//                 return;
//             }
//             else
//             {
//                 posCnt++;
//                 pos.push_back(j);
//                 s.insert(j, "01");
//             }
//         }
//         i++;
//         j--;
//     }
//     cout << posCnt << endl;
//     for (int i = 0; i < pos.size(); i++)
//     {
//         cout << pos[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;

//         if (n & 1)
//         {
//             cout << "-1" << endl;
//         }
//         else
//         {
//             solve(n, s);
//         }
//     }
//     return 0;
// }