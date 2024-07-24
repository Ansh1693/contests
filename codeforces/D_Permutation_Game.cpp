#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int calculate_scores(int pos, vector<int> &a, vector<int> &p, int k)
{
    int best = 0, curr = 0;

    for (int i = 0; i < a.size() && i < k; i++)
    {
        curr += a[pos - 1];
        best = max(best, curr + a[pos - 1] * (k - i - 1));
        pos = p[pos - 1];
    }

    return best;
}

void solve()
{
    int n, k, p_bodh, p_sasha;
    cin >> n >> k >> p_bodh >> p_sasha;
    vector<int> a(n), p(n);

    bool check = true;
    bool check2 = true;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] != i + 1)
        {
            check2 = false;
        }

        // p[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (i > 0 && check)
        {
            check = a[i] == a[i - 1];
        }
    }

    if (check)
    {
        cout << "Draw\n";
        return;
    }

    if (check2)
    {
        if (a[p_bodh - 1] > a[p_sasha - 1])
        {
            cout << "Bodya\n";
            return;
        }
        else if (a[p_sasha - 1] > a[p_bodh - 1])
        {
            cout << "Sasha\n";
            return;
        }
        else
        {
            cout << "Draw\n";
            return;
        }
    }

    int bodh_score = calculate_scores(p_bodh, a, p, k);
    int sasha_score = calculate_scores(p_sasha, a, p, k);

    if (bodh_score == sasha_score)
    {
        cout << "Draw\n";
    }
    else if (bodh_score > sasha_score)
    {
        cout << "Bodya\n";
    }
    else
    {
        // cout << bodh_score << " " << sasha_score;
        cout << "Sasha\n";
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}