#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long countSubarrays(long long n, vector<long long> &arr)
{
    unordered_map<long long, long long> remainderCount;
    long long prefixSum = 0;
    long long result = 0;

    for (long long num : arr)
    {
        prefixSum += num;
        long long remainder = prefixSum % n;

        if (remainder < 0)
        {
            remainder += n;
        }

        if (remainder == 0)
        {
            result++;
        }

        if (remainderCount.find(remainder) != remainderCount.end())
        {
            result += remainderCount[remainder];
            remainderCount[remainder]++;
        }
        else
        {
            remainderCount[remainder] = 1;
        }
    }

    return result;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << countSubarrays(n, arr) << endl;

    return 0;
}
