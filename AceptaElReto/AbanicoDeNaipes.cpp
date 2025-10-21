// TODO: Fix
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> sorted(v.begin(), v.end());
    sort(sorted.begin(), sorted.end());

    int maxLCIS = 0;

    int curr = (sorted[0] == v[0]);
    for (int i = 1; i < n; i++) {
      if (v[i] == sorted[i]) {
        curr++;
      } else {
        curr = 1;
      }

      maxLCIS = max(maxLCIS, curr);
    }

    cout << n - maxLCIS << "\n";
  }
}
