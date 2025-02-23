#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> a(n), prefixMin(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      prefixMin[i] = min(a[i], (i > 0 ? prefixMin[i - 1] : INT_MAX));
    }

    bool premio = true;
    set<int> vistos = {a[n - 1]};
    for (int i = n - 2; i > 0; i--) {
      if (prefixMin[i - 1] < a[i]) {

        auto it = vistos.lower_bound(prefixMin[i - 1]);
        if (it != vistos.end()) {
          int posibleMedio = *it;

          if (posibleMedio < a[i]) {
            premio = false;
            break;
          }
        }

      }
      vistos.insert(a[i]);
    }

    cout << (premio ? "SIEMPRE PREMIO" : "ELEGIR OTRA") << endl;

  }

  return 0;
}
