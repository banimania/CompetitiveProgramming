#include <bits/stdc++.h>
using namespace std;

double calcTime(double x0, vector<int> &x, vector<int> &t) {
  double ans = 0;

  for (int i = 0; i < x.size(); i++) {
    ans = max(ans, abs(x0 - x[i]) + t[i]);
  }
  
  return ans;
}

void solve() {
  int n;
  cin >> n;

  vector<int> x(n), t(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> t[i];

  double low = *min_element(x.begin(), x.end());
  double high = *max_element(x.begin(), x.end());

  while (abs(high - low) > 1e-7) {
    double c1 = (high - low) / 4.0f + low;
    double c3 = 3.0f * (high - low) / 4.0f + low;

    double t1 = calcTime(c1, x, t);
    double t3 = calcTime(c3, x, t);

    if (t1 >= t3) low = c1;
    if (t3 >= t1) high = c3;
  }

  cout << setprecision(20) << fixed << high << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
