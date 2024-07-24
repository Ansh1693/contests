
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool isBetter(int limit, vector<int> &threats, int k)
{
    int currSum = 0;
    int count = 1; // stores the minimum no of subteams can be formed using limit
    int i = 0;
    int n = threats.size();
    while (i < n)
    {
        // if number of sub-teams exceeds k, it means it is impossible to form subteams of k considering the current limit
        if (count > k)
        {
            return false;
        }

        currSum += threats[i];
        if (currSum > limit)
        {
            count++;
            currSum = threats[i];
        }

        i++;
    }
    return count <= k;
}

int splitTeam(vector<int> &threats, int k)
{
    int l = *max_element(threats.begin(), threats.end());  // minimum possible answer
    int r = accumulate(threats.begin(), threats.end(), 0); // maximum possible answer

    int ans = r;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // if mid could be possible answer
        if (isBetter(mid, threats, k))
        {
            ans = mid;
            r = mid - 1;
        }
        // if the mid is not the approperiate answer, try to find from mid to r
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{

    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        vector<int> threats(n);
        for (int i = 0; i < n; i++)
        {
            cin >> threats[i];
        }
        cout << splitTeam(threats, k) << endl;
    }
    return 0;
}