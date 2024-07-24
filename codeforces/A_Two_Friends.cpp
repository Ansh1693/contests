#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minInvitations(vector<int> &p)
{
    int n = p.size();
    vector<bool> invited(n + 1, false);
    int minInvites = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!invited[i])
        {
            int cur = i;
            int cnt = 0;
            while (!invited[cur])
            {
                invited[cur] = true;
                cur = p[cur - 1];
                ++cnt;
            }
            minInvites = max(2, cnt);
        }
    }

    return minInvites;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }

        cout << minInvitations(p) << endl;
    }

    return 0;
}
