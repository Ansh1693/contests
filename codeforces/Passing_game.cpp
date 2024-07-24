#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

long long minTime(int n, int k, vector<int> &x, vector<int> &s)
{
    vector<long long> dp(n + 1, INF);

    dp[1] = 0; // Initial position, no change in direction

    for (int i = 1; i <= n; ++i)
    {
        vector<long long> temp(dp);

        // Direct pass from i to n
        dp[n] = min(dp[n], temp[i] + 1LL * s[i - 1] * abs(x[i - 1] - x[n - 1]));

        // Change direction at i
        if (k > 0)
        {
            dp[i] = min(dp[i], temp[i]);
        }

        // Pass from i to j
        for (int j = i + 1; j <= n; ++j)
        {
            dp[j] = min(dp[j], temp[i] + 1LL * s[i - 1] * abs(x[i - 1] - x[j - 1]));
        }
    }

    return dp[n];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> x(n);
        vector<int> s(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> x[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
        }

        long long ans = minTime(n, k, x, s);
        cout << ans << endl;
    }

    return 0;
}