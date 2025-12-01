#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
  double x, y;

  Point() {}
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
};

// Intersección de AB con CD usando Cramer
Point intersect(const Point &A, const Point &B, const Point &C, const Point &D) {
  double det = (D.x - C.x) * (-(B.y - A.y)) - (D.y - C.y) * (-(B.x - A.x)); // si det == 0, AB es paralelo a CD

  double s = ((A.x - C.x) * (-(B.y - A.y)) - (A.y - C.y) * (-(B.x - A.x))) / det;

  Point P = {C.x + (D.x - C.x) * s, C.y + (D.y - C.y) * s};
  return P;
}

// Área, con el Shoelace Theorem
double poly_area(const vector<Point> &poly) {
  double area = 0;
  int n = poly.size();
  for(int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
  }
  return fabs(area) / 2.0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    Point D(B.x + (C.x - B.x) / 3.0, B.y + (C.y - B.y) / 3.0);
    Point E(C.x + (A.x - C.x) / 3.0, C.y + (A.y - C.y) / 3.0);
    Point F(A.x + (B.x - A.x) / 3.0, A.y + (B.y - A.y) / 3.0);

    Point P = intersect(B, E, A, D);
    Point Q = intersect(B, E, C, F);
    Point R = intersect(C, F, A, D);

    double area = poly_area({P, Q, R});

    cout << llround(area) << "\n";
  }
  return 0;
}
