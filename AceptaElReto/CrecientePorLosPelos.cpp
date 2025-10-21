#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int j = 0;
    for (int i = n - 1; i > 0; i--) {
      if (v[i] == v[i - 1]) {
        j = i;
        break;
      }
    }

    v[j]++;

    for (int i = j + 1; i < n; i++) {
      v[i] = v[j];
    }

    for (int i = 0; i < n; i++) {
      cout << v[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
  }

  return 0;
}
