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

  double dif = DBL_MAX;
  while (dif >= 1e-8) {
    double c1 = (high - low) / 4.0f + low;
    double c3 = 3.0f * (high - low) / 4.0f + low;

    double t1 = calcTime(c1, x, t);
    double t3 = calcTime(c3, x, t);

    double prevLow = low, prevHigh = high;
    if (t1 >= t3) low = c1 + 1e-8;
    if (t3 >= t1) high = c3 - 1e-8;

    dif = abs(low - prevLow) + abs(high - prevHigh);
  }

  cout << high << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
