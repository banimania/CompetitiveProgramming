#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int main() {
  int w, h, n;
  while (cin >> w >> h >> n) {
    vector<vector<bool>> mapa(h, vector<bool>(w, false));
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;

      mapa[y][x] = true;
    }

    pair<int, int> inicio, final;
    cin >> inicio.second >> inicio.first >> final.second >> final.first;

    vector<vector<int>> minSteps(h, vector<int>(w, INT_MAX));

    queue<pair<int, int>> q;
    q.push({inicio.first, inicio.second});
    minSteps[inicio.first][inicio.second] = 0;

    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      int steps = minSteps[i][j];

      if (i == final.first && j == final.second) {
        break;
      }

      for (int dir = 0; dir < dirs.size(); dir++) {
        int newI = i + dirs[dir].first;
        int newJ = j + dirs[dir].second;

        if (newI >= 0 && newI < h && newJ >= 0 && newJ < w && mapa[newI][newJ] && minSteps[newI][newJ] > minSteps[i][j] + 1) {
          minSteps[newI][newJ] = minSteps[i][j] + 1;
          q.push({newI, newJ});
        }
      }
    }

    if (minSteps[final.first][final.second] == INT_MAX) cout << 0 << endl;
    else cout << minSteps[final.first][final.second] << endl;

  }
}
