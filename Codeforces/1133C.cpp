#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int ans = 1;

  for (int i = 0; i < n; i++) {
    int index = lower_bound(a.begin(), a.end(), a[i] - 5) - a.begin();
    int len = i - index + 1;

    ans = max(ans, i - index + 1);
  }

  cout << ans << endl;

  return 0;
}
