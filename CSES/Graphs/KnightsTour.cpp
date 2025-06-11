#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool isValidMove(int x, int y, vector<vector<int>> &visited) {
  return x >= 0 && x < 8 && y >= 0 && y < 8 && !visited[x][y];
}

bool solve(int x, int y, vector<vector<int>> &visited, int cnt) {
  if (cnt == 65) {
    return true;
  }

  vector<tuple<int, int, int>> moves;
  for (int dir = 0; dir < dirs.size(); dir++) {
    int dx = dirs[dir].first;
    int dy = dirs[dir].second;

    int newX = x + dx;
    int newY = y + dy;

    if (isValidMove(newX, newY, visited)) {
      visited[newX][newY] = true;
      int next = 0;
      for (int newDir = 0; newDir < dirs.size(); newDir++) {
        int ndx = dirs[newDir].first;
        int ndy = dirs[newDir].second;

        int nextX = newX + ndx;
        int nextY = newY + ndy;

        if (isValidMove(nextX, nextY, visited)) next++;
      }

      visited[newX][newY] = false;
      moves.push_back({next, dx, dy});
    }

  }

  sort(moves.begin(), moves.end(), [](const tuple<int, int, int> &ta, const tuple<int, int, int> &tb) {
    return get<0>(ta) < get<0>(tb);
  });

  for (int move = 0; move < moves.size(); move++) {
    int dx = get<1>(moves[move]);
    int dy = get<2>(moves[move]);

    int newX = x + dx;
    int newY = y + dy;

    if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && !visited[newX][newY]) {
      visited[newX][newY] = cnt;
      if (solve(newX, newY, visited, cnt + 1)) return true;
      visited[newX][newY] = 0;
    }

  }

  return false;
}

int main() {
  int x, y;
  cin >> x >> y;
  x--, y--;

  vector<vector<int>> visited(8, vector<int>(8));
  visited[x][y] = 1;

  solve(x, y, visited, 2);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cout << visited[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
