#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
vector<int> arr;

int binSearch(vector<int> &arr, int l, int r)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= l)
        {
            ans = mid + 1;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    int ans1 = n + 1;
    start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= r)
        {
            ans1 = mid + 1;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    if (ans == 0 && ans1 == n + 1)
        return 0;

    if (ans == 0)
        return ans1;

    if (ans1 == n + 1)
        return n - ans + 1;

    return ans1 - ans + 1;
}

int main()
{
    int n, k;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    cin >> k;

    int l, r;

    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
        cout << binSearch(arr, l, r) << " ";
    }

    return 0;
}