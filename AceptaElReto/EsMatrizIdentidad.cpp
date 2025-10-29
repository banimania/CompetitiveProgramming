#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int l;
  while (cin >> l && l) {
    bool id = true;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        int x;
        cin >> x;
        if ((i == j && x != 1) || (i != j && x != 0)) {
          id = false;
        }
      }
    }

    cout << (id ? "SI\n" : "NO\n");
  }
  return 0;
}
