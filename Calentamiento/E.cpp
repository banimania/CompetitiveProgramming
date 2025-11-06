#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m, n;
  while (cin >> m >> n) {
    if (!m && !n) break;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    bool ans = true;
    int nd8 = n / 8;
    int md8 = m / 8;
    for (int i = 0; i < nd8 && ans; i++) {
      for (int j = 0; j < md8 && ans; j++) {
        unordered_set<char> used;

        int newI = i * 8;
        int newJ = j * 8;
        int nextI = (i + 1) * 8;
        int nextJ = (j + 1) * 8;

        for (int actI = newI; actI < nextI; actI++) {
          for (int actJ = newJ; actJ < nextJ; actJ++) {
            used.insert(grid[actI][actJ]);
          }
        }

        if (used.size() > 2) ans = false;
      }
    }
    cout << (ans ? "SI" : "NO") << "\n";
  }

  return 0;
}
