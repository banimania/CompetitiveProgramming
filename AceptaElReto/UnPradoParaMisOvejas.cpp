#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point {
  double x, y;
  bool operator == (const point& t) const {
    return x == t.x && y == t.y;
  }
  point operator - (const point& t) const {
    return {x - t.x, y - t.y};
  }
};

double cross(point a, point b) {
  return a.x*b.y - a.y * b.x;
}

int orientation(point a, point b, point c) {
  double v = cross(b - a, c - a); //cross product 2D de dos puntos
  if (v < 0) return -1;
  if (v > 0) return +1;
  return 0;
}

bool cw (point a, point b, point c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}

bool ccw (point a, point b, point c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o > 0 || (include_collinear && o == 0);
}

bool collinear (point a, point b, point c) {
  return orientation(a,b,c) == 0;
}

void convex_hull (vector<point>& a, bool include_collinear = false) {
  point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
  });
  sort (a.begin(), a.end(), [&p0] (const point& a, const point& b) {
    int o = orientation(p0, a, b);
    if (o == 0)
      // si son colineales, primero se mira el punto más cercano
      return (p0.x - a.x)* (p0.x - a.x) +  (p0.y - a.y)* (p0.y - a.y) < (p0.x - b.x)* (p0.x - b.x) + (p0.y - b.y)* (p0.y - b.y);
    return o < 0;
    // o < 0 - clockwise; o > 0 counterclockwise
  });
  // invertir los puntos colineales para primero coger los más lejanos de p0
  if (include_collinear){
    int i = (int) a.size()-1;
    while (i >= 0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin()+i+1, a.end());
  }
  vector<point> st;
  for (int i=0; i < (int)a.size();  i++){
    // cambiar ccw - ordenar counterclockwise; cw - ordenar clockwise
    while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
      st.pop_back();
    st.push_back(a[i]);
  }
  // mirar los puntos duplicados
  if (!include_collinear && st.size() == 2 && st[0] == st[1]) {
    st.pop_back();
  }
  a = st;
}
void solve(int tt){
  int n; cin >> n;
  vector<point> a;
  for (int i = 0; i < n; i++) {
    double x,y; cin >> x >> y;
    a.push_back({x,y});
  }
  // convex hull
  convex_hull(a, true);

  cout << a.size() << endl;
  for (int i = 0; i < a.size(); i++) {
    cout << (ll)a[i].x << " " << (ll)a[i].y << endl;
  }
}

double area(const vector<point>& fig) {
  double res = 0;
  int n = fig.size();
  for (int i = 0; i < n; i++) {
    point p = fig[i];
    point q = fig[(i + 1) % n];
    res += p.x * q.y - q.x * p.y;
  }
  return fabs(res) / 2.0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<point> original(n);
    for (int i = 0; i < n; i++) {
      cin >> original[i].x >> original[i].y;
    }

    convex_hull(original, false);
    double a = area(original);
    if (a == (long long) a) {
      cout << fixed << (long long) a << "\n";
    } else {
      string str = to_string(a);

      while (str.back() == '0') str.pop_back();
      cout << str << "\n";
    }
  }
  return 0;
}
