#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b) {
    if (!a && !b) break;

    a--, b--;

    cout << min(abs(a - b), 99 - max(a, b) + min(a, b)) << "\n";

  }
  return 0;
}
