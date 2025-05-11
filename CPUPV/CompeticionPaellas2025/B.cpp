#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  stack<pair<int, int>> st;
  int ans = 0;
  vector<vector<bool>> visited(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j] && grid[i][j]) {
        visited[i][j] = true;
        st.push({i, j});
        ans++;

        while (!st.empty()) {
          int currI = st.top().first, currJ = st.top().second;
          st.pop();

          for (auto [dirI, dirJ] : dirs) {
            int newI = currI + dirI, newJ = currJ + dirJ;

            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && !visited[newI][newJ] && grid[newI][newJ]) {
              visited[newI][newJ] = true;
              st.push({newI, newJ});
            }
          }
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
