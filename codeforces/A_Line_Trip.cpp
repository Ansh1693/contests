#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define ld long double

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  a.push_back(x);
  a.push_back(0);

  sort(a.begin(), a.end());

  int ans = 0;

  int siz = a.size();

  for (int i = 1; i < a.size(); i++) {
    int d;
    if (i == siz - 1) {
      d = 2 * (a[i] - a[i - 1]);
    } else {

      d = a[i] - a[i - 1];
    }
    ans = max(ans, d);
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
