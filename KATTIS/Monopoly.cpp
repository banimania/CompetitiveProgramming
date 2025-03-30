#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> num(13);
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      num[i + j]++;
    }
  }

  double prob = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int fab = 0;
    if (x >= 2 && x <= 12) {
      fab = num[x];
    }

    prob += (fab / 36.0);
  }

  cout << fixed << setprecision(4) << prob << endl;
  return 0;
}
