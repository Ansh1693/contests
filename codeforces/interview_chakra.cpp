#include <bits/stdc++.h>

using namespace std;

int findMaxKSum(int n, vector<int> &array, int k)
{

    vector<int> prefixSum(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + array[i - 1];
    }

    int maxSum = INT_MIN;

    int left = 0, right = n;

    for (int i = 0; i <= k; i++)
    {
        int sumLeftforIelement = prefixSum[left + i] - prefixSum[left];
        int sumRightfork_iElement = prefixSum[right] - prefixSum[right - (k - i)];

        maxSum = max(maxSum, sumLeftforIelement + sumRightfork_iElement);
    }

    return maxSum;
}

int main()
{

    int len = 5;

    vector<int> array = {5, 10, 3, 2, 6};

    int k = 2;

    int answer = findMaxKSum(len, array, k);

    cout << "Maximum Sum is:" << answer << endl;

    return 0;
}