#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> alturas(n);
    for (int i = 0; i < n; i++) cin >> alturas[i];

    int ans = 0;
    int currMax = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (alturas[i] > currMax) ans++;

      currMax = max(currMax, alturas[i]);
    }

    cout << ans << endl;
  }

  return 0;
}
