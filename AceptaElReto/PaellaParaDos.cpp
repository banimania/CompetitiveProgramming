#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x;
  int y;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m, g;
  while (cin >> m >> g) {
    if (!m && !g) break;

    vector<Point> mejillones(m);
    for (int i = 0; i < m; i++) {
      cin >> mejillones[i].x >> mejillones[i].y;
    }
    vector<Point> gambas(g);
    for (int i = 0; i < g; i++) {
      cin >> gambas[i].x >> gambas[i].y;
    }

    bool divisible = false;

    for (int i = 0; i < m && !divisible; i++) {
      int nmej = 0, ngam = 0;

      if (mejillones[i].x == 0) {
        for (int j = 0; j < m; j++) {
          if (j == i) continue;

          if (mejillones[j].x > 0) {
            nmej++;
          } else {
            nmej--;
          }
        }
        for (int j = 0; j < g; j++) {
          if (gambas[j].x > 0) {
            ngam++;
          } else {
            ngam--;
          }
        }
      } else {
        float pendiente = mejillones[i].y / (float) mejillones[i].x;

        for (int j = 0; j < m; j++) {
          if (j == i) continue;

          if (mejillones[j].y > pendiente * mejillones[j].x) {
            nmej++;
          } else {
            nmej--;
          }
        }
        for (int j = 0; j < g; j++) {
          if (gambas[j].y > pendiente * gambas[j].x) {
            ngam++;
          } else {
            ngam--;
          }
        }
      }

      divisible = (!ngam && abs(nmej) <= 1);
    }

    for (int i = 0; i < g && !divisible; i++) {
      int nmej = 0, ngam = 0;

      if (gambas[i].x == 0) {
        for (int j = 0; j < m; j++) {
          if (mejillones[j].x > 0) {
            nmej++;
          } else {
            nmej--;
          }
        }
        for (int j = 0; j < g; j++) {
          if (j == i) continue;

          if (gambas[j].x > 0) {
            ngam++;
          } else {
            ngam--;
          }
        }
      } else {
        float pendiente = gambas[i].y / (float) gambas[i].x;

        for (int j = 0; j < m; j++) {
          if (mejillones[j].y > pendiente * mejillones[j].x) {
            nmej++;
          } else {
            nmej--;
          }
        }
        for (int j = 0; j < g; j++) {
          if (j == i) continue;

          if (gambas[j].y > pendiente * gambas[j].x) {
            ngam++;
          } else {
            ngam--;
          }
        }
      }

      divisible = (!nmej && abs(ngam) <= 1);
    }

    cout << (divisible ? "SI" : "NO") << "\n";
  }
  return 0;
}
