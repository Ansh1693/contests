// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;

        arr[i].second = i + 1;
    }

    int j = 0, k = n - 1;

    sort(arr.begin(), arr.end());

    while (j < k)
    {

        int sum = arr[j].first + arr[k].first;

        if (sum == x)
        {
            cout << arr[j].second << " " << arr[k].second;
            return 0;
        }
        else if (sum < x)
        {
            j++;
        }
        else
        {
            k--;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}