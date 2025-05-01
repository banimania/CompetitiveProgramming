#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, n;
  while (cin >> p >> n) {
    if (!p && !n) break;

    set<int> s = {p};
    auto medio = s.begin();
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;

      s.insert(a);
      s.insert(b);

      if (a > *medio && b > *medio) {
        medio++;
      } else if (a < *medio && b < *medio) {
        medio--;
      }

      cout << *medio << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }
  return 0;
}
