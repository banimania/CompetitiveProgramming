#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  n++, m++;

  vector<int> degP(n), degQ(m);

  for (int i = 0; i < n; i++) cin >> degP[i];
  for (int i = 0; i < m; i++) cin >> degQ[i];

  if (n > m) {
    cout << (degP[0] > 0 == degQ[0] > 0 ? "" : "-") << "Infinity" << endl;
  } else if (n == m) {
    for (int i = 2; i <= 100; i++) {
      while (degP[0] % i == 0 && degQ[0] % i == 0) {
        degP[0] /= i;
        degQ[0] /= i;
      }
    }

    if (degQ[0] < 0) {
      degQ[0] = abs(degQ[0]);
      degP[0] = -degP[0];
    }
    cout << degP[0] << "/" << degQ[0] << endl;
  } else {
    cout << "0/1" << endl;
  }

  return 0;
}
