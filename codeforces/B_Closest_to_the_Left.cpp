#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

// Given an array of n numbers, sorted in non-decreasing order, and k queries. For each query, print the maximum index of an array element not greater than the given one.

int binSearch(vector<int> &arr, int target)
{
    int start = 0, end = arr.size() - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= target)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int x;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
    {
        cin >> x;

        cout << binSearch(arr, x) + 1 << endl;
    }

    return 0;
}