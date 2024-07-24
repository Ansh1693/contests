// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double

// void solve()
// {

//     int n, m;
//     cin >> n >> m;
//     string s, t;
//     cin >> s;
//     cin >> t;

//     int j = 1;

//     bool ch = true;

//     while (j < m)
//     {
//         if (t[j] == t[j - 1])
//         {
//             ch = false;
//             break;
//         }

//         j++;
//     }

//     int i = 1;
//     while (i < n)
//     {
//         if (s[i] == s[i - 1])
//         {
//             // cout << i << " ";
//             if (ch == false)
//             {
//                 cout << "No" << endl;
//                 return;
//             }
//             if (t[0] == s[i - 1] || t[m - 1] == s[i])
//             {
//                 cout << "No" << endl;
//                 return;
//             }
//         }

//         i++;
//     }

//     cout << "Yes" << endl;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            if (t[0] == s[i] || t[m - 1] == s[i])
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    for (int i = 0; i < m - 1; i++)
    {
        if (t[i] == t[i + 1])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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