#include <bits/stdc++.h>
using namespace std;

double evaluate(vector<int> &c, double x) {
  double ans = 0;
  for (int i = 0; i < c.size(); i++) {
    ans += c[i] * pow(x, c.size() - i - 1);
  }
  return ans;
}

double areaCain(vector<int> &c, int n) {
  double area = 0;
  double dx = 1.0 / n;

  for (int i = 0; i < n; i++) {
    double x = i * dx;
    double y = evaluate(c, x);

    if (y < 0) y = 0;
    if (y > 1) y = 1;

    area += y * dx;
  }

  return area;
}

int main() {
  int g;
  while (cin >> g && g != 20) {
    vector<int> c(g + 1);
    for (int i = 0; i <= g; i++) cin >> c[i];

    int n;
    cin >> n;

    double a1 = areaCain(c, n);
    double a2 = 1 - a1;

    if (abs(a1 - a2) <= 0.001) {
      cout << "JUSTO" << endl;
    } else {
      cout << (a1 > a2 ? "CAIN" : "ABEL") << endl;
    }
  }

  return 0;
}
