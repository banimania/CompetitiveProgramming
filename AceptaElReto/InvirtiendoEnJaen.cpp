#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  int f, c;
  while (cin >> f >> c) {
    cin.ignore();
    vector<vector<char>> grid(f, vector<char>(c));

    for (int i = 0; i < f; i++) {
      string line;
      getline(cin, line);
      for (int j = 0; j < c; j++) {
        grid[i][j] = line[j];
      }
    }

    int ans = 0;
    stack<pair<int, int>> st;
    vector<vector<bool>> visited(f, vector<bool>(c));
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == '#' && !visited[i][j]) {
          int s = 1;
          visited[i][j] = true;
          st.push({i, j});

          while (!st.empty()) {
            int currI = st.top().first;
            int currJ = st.top().second;
            st.pop();

            for (int dir = 0; dir < dirs.size(); dir++) {
              int newI = currI + dirs[dir].first;
              int newJ = currJ + dirs[dir].second;

              if (newI >= 0 && newI < f && newJ >= 0 && newJ < c && grid[newI][newJ] == '#' && !visited[newI][newJ]) {
                visited[newI][newJ] = true;
                s++;
                st.push({newI, newJ});
              } 
            }
          }

          ans = max(ans, s);
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
