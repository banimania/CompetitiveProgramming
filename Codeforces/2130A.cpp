#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int sum = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    sum += x;

    if (!x) sum++;
  }

  cout << sum << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
