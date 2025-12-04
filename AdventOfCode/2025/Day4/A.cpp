#include <bits/stdc++.h>
using namespace std;

// vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll ans = 0;

  vector<string> a;
  string line;
  while (getline(cin, line)) {
    cout << line << endl;
    a.push_back(line);
  }

  int n = a.size();
  int m  = a[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '@') {
        int adj = 0;
        for (auto [dI, dJ] : dirs) {
          int newI = i + dI;
          int newJ = j + dJ;

          if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && a[newI][newJ] == '@') {
            adj++;
          }
        }

        if (adj < 4) {
          ans++;
        }

      }
    }
  }

  cout << ans << "\n";

  return 0;
}
