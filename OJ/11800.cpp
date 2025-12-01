#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double EPS = 1e-9;

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

// Si el determinante es 0, AB y CD son paralelos
bool parallelSegments(const Point &A, const Point &B, const Point &C, const Point &D) {
  return fabs((D.x - C.x) * (-(B.y - A.y)) - (D.y - C.y) * (-(B.x - A.x))) < EPS;
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

// Ángulo en radianes entre segmento AB y CD
double angle_segments(const Point &A, const Point &B, const Point &C, const Point &D) {
  double ux = B.x - A.x;
  double uy = B.y - A.y;

  double vx = D.x - C.x;
  double vy = D.y - C.y;

  double cross = ux * vy - uy * vx;
  double dot = ux * vx + uy * vy;

  return atan2(cross, dot);
}

// Cross product
double cross(const Point &O, const Point &A, const Point &B) {
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Ordenación polar de p (respecto ángulo con el punto más bajo)
void polar_order(vector<Point> &p) {
  if (p.empty()) return;

  Point O = *min_element(p.begin(), p.end(), [](const Point &a, const Point &b) {
    if (abs(a.y - b.y) < EPS) return a.x < b.x;
    return a.y < b.y;
  });

  sort(p.begin(), p.end(), [&](const Point &A, const Point &B) {
    double c = cross(O, A, B);
    if (abs(c) > EPS) return c > 0;

    // colineales XD
    double d1 = (A.x - O.x) * (A.x - O.x) + (A.y - O.y) * (A.y - O.y);
    double d2 = (B.x - O.x) * (B.x - O.x) + (B.y - O.y) * (B.y - O.y);
    return d1 < d2;
  });
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    vector<Point> p(4);
    for (int i = 0; i < 4; i++) {
      cin >> p[i].x >> p[i].y;
    }

    polar_order(p);

    double p0_p1Sq = ((p[0].x - p[1].x) * (p[0].x - p[1].x) + (p[0].y - p[1].y) * (p[0].y - p[1].y));
    double p1_p2Sq = ((p[1].x - p[2].x) * (p[1].x - p[2].x) + (p[1].y - p[2].y) * (p[1].y - p[2].y));
    double p2_p3Sq = ((p[2].x - p[3].x) * (p[2].x - p[3].x) + (p[2].y - p[3].y) * (p[2].y - p[3].y));
    double p3_p0Sq = ((p[3].x - p[0].x) * (p[3].x - p[0].x) + (p[3].y - p[0].y) * (p[3].y - p[0].y));

    double angleP0 = angle_segments(p[3], p[0], p[0], p[1]);
    double angleP1 = angle_segments(p[0], p[1], p[1], p[2]);
    double angleP2 = angle_segments(p[1], p[2], p[2], p[3]);
    double angleP3 = angle_segments(p[2], p[3], p[3], p[0]);

    double deg90 = M_PI / 2.0;

    bool allAnglesEqual = (fabs(angleP0 - angleP1) < EPS && fabs(angleP1 - angleP2) < EPS && fabs(angleP2 - angleP3) < EPS);
    bool allSidesEqual = (fabs(p0_p1Sq - p1_p2Sq) < EPS && fabs(p1_p2Sq - p2_p3Sq) < EPS && fabs(p2_p3Sq - p3_p0Sq) < EPS);
    bool noAngleIs90 = (fabs(angleP0 - deg90) >= EPS && fabs(angleP1 - deg90) >= EPS && fabs(angleP2 - deg90) >= EPS && fabs(angleP3 - deg90) >= EPS);
    bool oppositeSidesEqual = (fabs(p0_p1Sq - p2_p3Sq) < EPS && fabs(p1_p2Sq - p3_p0Sq) < EPS);
    bool trapezium = (parallelSegments(p[0], p[1], p[2], p[3]) && !parallelSegments(p[1], p[2], p[3], p[0])) || (!parallelSegments(p[0], p[1], p[2], p[3]) && parallelSegments(p[1], p[2], p[3], p[0]));

    cout << "Case " << tt << ": ";
    if (allSidesEqual && allAnglesEqual) {
      cout << "Square\n";
    } else if (allAnglesEqual) {
      cout << "Rectangle\n";
    } else if (allSidesEqual && noAngleIs90) {
      cout << "Rhombus\n";
    } else if (oppositeSidesEqual && noAngleIs90) {
      cout << "Parallelogram\n";
    } else if (trapezium) {
      cout << "Trapezium\n";
    } else {
      cout << "Ordinary Quadrilateral\n";
    }

  }
  return 0;
}
