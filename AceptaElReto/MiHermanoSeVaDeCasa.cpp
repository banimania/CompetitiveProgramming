#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  double w, h, p1, p2;
  while (cin >> w >> h >> p1 >> p2) {
    double a = max(w, h);
    double b = min(w, h);

    double Pg = max(p1, p2);
    double Pp = min(p1, p2);

    double x1 = sqrt(Pp * Pp - b * b);
    double x2 = sqrt(Pg * Pg - b * b);

    bool ans = x1 + x2 >= a;

    cout << (ans ? "SI" : "NO") << "\n";
  }

  return 0;
}
