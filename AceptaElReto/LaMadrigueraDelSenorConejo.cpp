#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  while (cin >> n && n) {
    vector<multiset<int>> m(21);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      m[x].insert(i);
      a[i] = x;
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      int minPos = INT_MAX;
      int selectedX = -1, selectedPos = n;
      for (int j = a[i] + 1; j < 21; j++) {
        if (!m[j].empty()) {
          auto it = m[j].upper_bound(i);

          int pos = (it == m[j].end() ? n : *it);

          if (pos < minPos) {
            minPos = pos;
            selectedPos = pos;
            selectedX = j;
          }
        }
      }

      cnt += selectedPos - i;
    }

    cout << cnt << endl;
  }
  return 0;
}
