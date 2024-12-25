#include <iostream>
using namespace std;

const int MOD = 998244353;

// Function to compute x^y % MOD
long long mod_exp(long long x, long long y, long long mod)
{
    long long result = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

// Function to compute modular inverse using Fermat's Little Theorem
long long mod_inverse(long long a, long long mod)
{
    return mod_exp(a, mod - 2, mod);
}

int main()
{
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; ++case_num)
    {
        long long W, G, L;
        cin >> W >> G >> L;

        long long p, q;
        if (L == 0)
        {
            // If L == 0, you can only lose weight, never gain, so it's a direct subtraction
            p = W - G;
            q = 1;
        }
        else
        {
            // If L > 0, calculate expected days using the random walk and constraints
            if (W == G + 1)
            {
                // Simple case where you're one step away from goal
                p = 2;
                q = 1;
            }
            else
            {
                // General case: You either step towards G or away from it, forcing steps based on L
                p = 2 * (W - G); // Simplified form of the expected number of days
                q = 1;           // Denominator in this simplified form
            }
        }

        // Compute the final result as p * q^(-1) % MOD
        long long result = (p * mod_inverse(q, MOD)) % MOD;

        // Output the result for this test case
        cout << "Case #" << case_num << ": " << result << endl;
    }

    return 0;
}
