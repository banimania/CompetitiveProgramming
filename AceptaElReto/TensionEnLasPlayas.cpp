#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Circle {
  int x, y, r;
};

bool circleIntersect(const Circle &a, const Circle &b) {
  double dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
  return dist < a.r + b.r;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<Circle> sombrillas(n);
    for (int i = 0; i < n; i++) {
      int x, y, r;
      cin >> x >> y >> r;

      sombrillas[i] = {x, y, r};
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {

        if (circleIntersect(sombrillas[i], sombrillas[j])) ans++;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
