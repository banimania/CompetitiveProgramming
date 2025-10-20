#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;

    cout << (n % 2 ? n - 1 : n + 1) << "\n";
  }
  return 0;
}
