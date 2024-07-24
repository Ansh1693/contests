#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    long long countPairs = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j * j <= arr[i]; ++j)
        {
            if (arr[i] % j == 0)
            {
                countPairs += freq[j];
                if (j * j != arr[i])
                {
                    countPairs += freq[arr[i] / j];
                }
            }
        }
        freq[arr[i]]++;
    }

    cout << countPairs << endl;

    return 0;
}
