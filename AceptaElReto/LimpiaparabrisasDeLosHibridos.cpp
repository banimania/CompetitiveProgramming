#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int l;
  while (cin >> l && l) {
    int r;
    cin >> r;

    bool disp[16] = {};
    for (int i = 0; i < r; i++) {
      int x;
      cin >> x;

      disp[x] = true;
    }

    bool progress = true;
    while (progress) {
      progress = false;

      for (int i = 1; i <= 15; i++) {
        if (!disp[i]) continue;
        for (int j = 1; j < i; j++) {
          if (!disp[j]) continue;

          if (!disp[i - j]) {
            disp[i - j] = true;
            progress = true;
          }
        }
      }
    }

    cout << (disp[l] ? "SI\n" : "NO\n");
  }
  return 0;
}
