#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    int maxAltura = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] + i >= maxAltura) {
        maxAltura = a[i] + i;
      }
    }

    for (int i = 0; i < n; i++) {
      cout << maxAltura - (a[i] + i) << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }
  return 0;
}
