#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mexPrefix(n);
    int cMex = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == cMex) cMex++;
      mexPrefix[i] = cMex;
    }

    vector<int> mexSuffix(n);
    cMex = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == cMex) cMex++;
      mexSuffix[i] = cMex;
    }

    bool possible = false;

    for (int i = 0; i < n - 1; i++) {
      if (mexPrefix[i] == mexSuffix[i + 1]) {
        possible = true;
        cout << 2 << endl;
        cout << 1 << " " << i + 1 << endl;
        cout << i + 2 << " " << n << endl;
        break;
      }
    }

    if (!possible) {
      cout << -1 << endl;
    }
  }
  return 0;
}
