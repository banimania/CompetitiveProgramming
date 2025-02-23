#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int alcance = INT_MIN;
  int maximo = INT_MIN;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (maximo != INT_MIN) alcance = max(alcance, maximo - x);

    maximo = max(x, maximo);
  }

  cout << alcance << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
