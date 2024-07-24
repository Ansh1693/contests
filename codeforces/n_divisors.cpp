#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> calculateDivisorsCount(int max)
{
    vector<int> divisorsCount(max + 1, 0);
    for (int i = 1; i <= max; ++i)
    {
        for (int j = i; j <= max; j += i)
        {
            divisorsCount[j]++;
        }
    }
    return divisorsCount;
}

int main()
{
    int a, b, n;
    cin >> a >> b >> n;

    // Precompute divisors count for all numbers up to b
    vector<int> divisorsCount = calculateDivisorsCount(b);

    int ans = 0;
    for (int i = a; i <= b; ++i)
    {
        if (divisorsCount[i] == n)
            ans++;
    }

    cout << ans;

    return 0;
}
