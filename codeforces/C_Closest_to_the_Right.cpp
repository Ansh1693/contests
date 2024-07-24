#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
vector<int> arr;

int binSearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    int ans = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    arr.resize(n);
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