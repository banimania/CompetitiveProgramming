#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 && y1 == y2) {
      cout << 0 << endl;
      continue;
    }

    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
      cout << "IMPOSIBLE" << endl;
    } else {
      if (x2 - x1 == 0) {
        cout << 2 << endl;
      } else {
        double pendiente = (y2 - y1) / (double)(x2 - x1);
        if (abs(pendiente) == 1) {
          cout << 1 << endl;
        } else {
          cout << 2 << endl;
        }
      }
    }
  }
  return 0;
}
