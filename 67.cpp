#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    unordered_set<int> visited;
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited.insert(n);

    while (!q.empty()) {
      auto [curr, currOps] = q.front();
      q.pop();

      if (curr == 67) {
        cout << currOps << "\n";
        break;
      }

      int nPlus7 = curr + 7;
      if (!visited.count(nPlus7)) {
        visited.insert(nPlus7);
        q.push({curr + 7, currOps + 1});
      }
      int nDiv6 = curr / 6;
      if (!visited.count(nDiv6)) {
        visited.insert(nDiv6);
        q.push({nDiv6, currOps + 1});
      }
    }
  }

  return 0;
}
