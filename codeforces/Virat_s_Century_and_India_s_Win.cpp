
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int count_ways(int N, int b, int w, int x, unordered_map<long long, int> &memo)
{
    // Base cases
    if (N <= 0)
        return 1; // India has won
    if (b <= 0 || w >= 10)
        return 0; // No more balls or all wickets are down

    // Check if the state is already memoized
    long long state = (long long)N * 1000000000LL * 10000LL * 100LL + b * 10000LL * 100LL + w * 100LL + x;
    if (memo.find(state) != memo.end())
    {
        return memo[state];
    }

    // Initialize the probability
    int total_ways = 0;

    // Loop through all possibilities (out, 1, 2, 3, 4, 6)
    for (int run : {0, 1, 2, 3, 4, 6})
    {
        if (run == 0 && x == 0)
            continue; // Skip the possibility of scoring 0 when Virat has not scored anything

        // Calculate the new state after the ball
        int new_N = N - run;
        int new_b = b - 1;
        int new_w = w + (run == 0);
        int new_x = (x + run) % 100;

        // Recursive call to calculate the total number of ways
        total_ways = (total_ways + count_ways(new_N, new_b, new_w, new_x, memo)) % MOD;
    }

    // Memoize the result
    memo[state] = total_ways;

    return total_ways;
}

vector<int> find_probability(int T, vector<vector<int>> &test_cases)
{
    vector<int> results;

    for (int i = 0; i < T; ++i)
    {
        int N = test_cases[i][0];
        int b = test_cases[i][1];
        int w = test_cases[i][2];
        int x = test_cases[i][3];

        // Calculate and print the results
        unordered_map<long long, int> memo;
        int total_ways = count_ways(N, b, w, x, memo);
        int probability = (int)((long long)total_ways * pow(6, b)) % MOD;
        results.push_back(probability);
    }

    return results;
}

int main()
{
    // Input reading
    int T;
    cin >> T;
    vector<vector<int>> test_cases(T, vector<int>(4));
    for (int i = 0; i < T; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> test_cases[i][j];
        }
    }

    // Calculate and print the results
    vector<int> results = find_probability(T, test_cases);
    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}
