#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> time(n);
  int suma = 0;
  for (int i = 0; i < n; i++) {
    cin >> time[i];
    suma += time[i];
  }

  bitset<8001> dp;
  dp[0] = 1;

  for (int t : time) {
    dp |= (dp << t);
  }

  int a = 0, b = INT_MAX;

  for (int i = 0; i <= 8000; i++) {
    if (dp[i]) {
      if (abs(i - (suma - i)) < abs(b - a)) {
        a = min(suma - i, i);
        b = max(suma - i, i);
      }
    }
  }

  cout << a << " " << b << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
