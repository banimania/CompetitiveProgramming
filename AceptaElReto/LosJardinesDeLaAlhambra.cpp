#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  int f, c;
  while (cin >> f >> c) {
    vector<vector<bool>> visitado(f, vector<bool>(c, true));
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        char x;
        cin >> x;

        if (x == '#') visitado[i][j] = false;
     }
    }

    int cnt = 0;

    queue<pair<int, int>> q;
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (!visitado[i][j]) {
          visitado[i][j] = true;
          cnt++;
          q.push({i, j});
          while (!q.empty()) {
            int currI = q.front().first;
            int currJ = q.front().second;
            q.pop();

            for (int dir = 0; dir < dirs.size(); dir++) {
              int dirI = dirs[dir].first;
              int dirJ = dirs[dir].second;

              int newI = currI + dirI;
              int newJ = currJ + dirJ;

              if (newI >= 0 && newI < f && newJ >= 0 && newJ < c && !visitado[newI][newJ]) {
                visitado[newI][newJ] = true;
                q.push({newI, newJ});
              }
            }
          }
        }
      }
    }

    cout << cnt << endl;
  }
  return 0;
}
