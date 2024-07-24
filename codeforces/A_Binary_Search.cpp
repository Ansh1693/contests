#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define ld long double

bool binSearch(vector<int> &arr, int target) {
  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
      return true;
    else if (arr[mid] > target)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  int x;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < k; i++) {
    cin >> x;

    if (binSearch(arr, x))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
