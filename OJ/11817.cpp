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

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  const int R = 6371009;

  while (t--) {
    double latA, latB, lonA, lonB;
    cin >> latA >> lonA >> latB >> lonB;

    latA *= (M_PI / 180.0);
    latB *= (M_PI / 180.0);
    lonA *= (M_PI / 180.0);
    lonB *= (M_PI / 180.0);

    long double x1 = R * cos(latA) * cos(lonA); 
    long double x2 = R * cos(latB) * cos(lonB); 

    long double y1 = R * cos(latA) * sin(lonA); 
    long double y2 = R * cos(latB) * sin(lonB); 

    long double z1 = R * sin(latA);
    long double z2 = R * sin(latB);

    double difX = abs(x2 - x1);
    double difY = abs(y2 - y1);
    double difZ = abs(z2 - z1);

    double dist1 = sqrt((difX * difX) + (difY * difY) + (difZ * difZ));
    
    long double num1 = (x1 * x2) + (z1 * z2) + (y1 * y2);
    long double num2 = (long double) R * R;
    long double dist2 = R * acos(num1 / num2);
    cout << fixed << llround(abs(dist1 - dist2)) << endl;
  }

  return 0;
}
