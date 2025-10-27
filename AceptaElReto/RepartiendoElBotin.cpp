#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, b, x;
  while (cin >> b >> n) {
    if (!n && !b) break;

    vector<pair<int, vector<int>>> persona(n);
    for (int i = 0; i < b; i++) {
      cin >> x;
      persona[i % n].first += x;
      persona[i % n].second.push_back(x);
    }

    for (int i = 0; i < n; i++) {
      cout << persona[i].first << ":";
      for (int j = 0; j < persona[i].second.size(); j++) {
        cout << " " << persona[i].second[j];
      }
      cout << "\n";
    }

    cout << "---\n";
  }
  return 0;
}
