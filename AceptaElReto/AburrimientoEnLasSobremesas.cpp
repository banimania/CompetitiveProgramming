#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    if (!n) break;

    cout << 3 * (n * (n + 1) / 2) << '\n';
  }
  return 0;
}
