#include <bits/stdc++.h>
using namespace std;

void solve() {
  int longitud, antenas;
  cin >> longitud >> antenas;

  bool cubre = true;

  vector<pair<int, int>> a;
  for (int i = 0; i < antenas; i++) {
    int centro, radio;
    cin >> centro >> radio;

    a.push_back({centro - radio, centro + radio});
  }

  sort(a.begin(), a.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
  });

  int c1 = a[0].first, c2 = a[0].second;
  for (int i = 1; i < antenas; i++) {
    if (a[i].first > c2) cubre = false;
    c2 = max(c2, a[i].second);
  }

  if (c1 > 0 || c2 < longitud) cubre = false;

  cout << (cubre ? "SI" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
