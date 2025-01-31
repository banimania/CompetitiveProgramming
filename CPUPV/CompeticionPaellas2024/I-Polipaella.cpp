#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
  long double x, y;
};

void solve() {
  ll v;
  cin >> v;

  vector<Point> points(v);
  for (int i = 0; i < v; i++) {
    cin >> points[i].x >> points[i].y;
  }

  ll numP;
  cin >> numP;

  for (int i = 0; i < numP; i++) {
    Point p;
    cin >> p.x >> p.y;

    ll intersections = 0;
    for (int j = 0; j < points.size(); j++) {
      Point p1 = points[j];
      Point p2 = points[(j + 1) % points.size()];

      if (p.y >= min(p1.y, p2.y) && p.y <= max(p1.y, p2.y)) {
        long double xInt = p1.x + (p.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);

        if (xInt > p.x) intersections++;
      }

    }

    cout << (intersections % 2 == 1 ? "DENTRO" : "FUERA") << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
