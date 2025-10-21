#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<pair<int, int>> ciudades(n);
    for (int i = 0; i < n; i++) {
      cin >> ciudades[i].first >> ciudades[i].second;
    }

    sort(ciudades.begin(), ciudades.end());

    bool justo = true;

    for (int i = 1; i < ciudades.size() && justo; i++) {
      if (ciudades[i].first > ciudades[i - 1].first) {
        justo &= (ciudades[i].second > ciudades[i - 1].second);
      }
    }
    
    cout << (justo ? "SI" : "NO") << "\n";
  }

  return 0;
}
