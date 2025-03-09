#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve() {
  int n;
  cin >> n;
  vector<vector<bool>> a(n, vector<bool>(n, false)), visited(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      a[i][j] = x - '0';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] && !visited[i][j]) {
        bool touchedWall = false;
        visited[i][j] = true;
        stack<pair<int, int>> st;
        st.push({i, j});
        while (!st.empty()) {
          int currI = st.top().first;
          int currJ = st.top().second;
          st.pop();

          if (currI == n - 1 || currJ == n - 1) {
            touchedWall = true;
          }

          if (((currI + 1) < n && !a[currI + 1][currJ]) && (currJ + 1) < n && !a[currI][currJ + 1]) {
            cout << "NO" << endl;
            return;
          }

          for (auto [dirI, dirJ] : dirs) {
            int newI = currI + dirI;
            int newJ = currJ + dirJ;

            if (newI >= 0 && newJ >= 0 && newI < n && newJ < n && a[newI][newJ] && !visited[newI][newJ]) {
              visited[newI][newJ] = true;
              st.push({newI, newJ});
            }
          }

        }

        if (!touchedWall) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }

  cout << "YES" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
