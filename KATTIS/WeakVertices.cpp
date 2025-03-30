#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != -1) {
    map<int, set<int>> adj;
    for (int i = 0; i < n; i++) adj[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;

        if (x) {
          adj[i].insert(j);
        }
      }
    }

    vector<int> weak;
    for (auto [i, s] : adj) {
      if (s.size() < 2) {
        weak.push_back(i);
        continue;
      } else {
        bool w = true;
        for (int j : s) {
          for (int k : s) {
            if (j == k) continue;

            if (adj[j].count(k)) {
              w = false;
              break;
            }
          }
          if (!w) break;
        }

        if (w) weak.push_back(i);
      }
    }

    for (int i = 0; i < weak.size(); i++) {
      cout << weak[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
