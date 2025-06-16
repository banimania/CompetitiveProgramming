#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visible) {

  for (int dir = 0; dir < dirs.size(); dir++) {
    int newI = i + dirs[dir].first;
    int newJ = j + dirs[dir].second;

    if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && !visible[newI][newJ]) {
      visible[newI][newJ] = true;

      if (grid[newI][newJ] == '0') dfs(newI, newJ, grid, visible);
    }
  }

}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visible(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '*') continue;

        int b = 0;
        for (int dir = 0; dir < dirs.size(); dir++) {
          int newI = i + dirs[dir].first;
          int newJ = j + dirs[dir].second;

          if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == '*') b++;
        }

        grid[i][j] = '0' + b;
      }
    }

    bool gameOver = false;

    int k;
    cin >> k;

    for (int x = 0; x < k; x++) {
      int i, j;
      cin >> i >> j;

      i--, j--;

      if (grid[i][j] == '*') gameOver = true;

      if (gameOver) continue;

      if (!visible[i][j]) {
        visible[i][j] = true;
        if (grid[i][j] == '0') dfs(i, j, grid, visible);
      }
    }

    if (gameOver) {
      cout << "GAME OVER" << endl;
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (!visible[i][j]) cout << 'X';
          else {
            cout << (grid[i][j] == '0' ? '-' : grid[i][j]);
          }
        }
        cout << endl;
      }
    }
  }
  return 0;
}
