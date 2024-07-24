#include <bits/stdc++.h>

using namespace std;

bool check_combinations(const vector<string> &A, int j, unordered_map<int, bool> mp)
{
    int N = A.size();
    int K = A[0].size();

    for (int mask = 0; mask < (1 << N); ++mask)
    {
        int result = 0;
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1 << i))
            {
                int num = stoi(A[i], nullptr, 2);
                result |= num;
            }
        }
        mp[result] = true;
        if (result == j)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<string> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }
        unordered_map<int, bool> mp;

        bool possible = true;
        for (int j = 1; j < (1 << K); ++j)
        {
            if (!mp[j] && !check_combinations(A, j, mp))
            {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}
