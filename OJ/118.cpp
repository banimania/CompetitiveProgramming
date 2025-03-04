#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 0

pair<int, int> getCurrentDirection(char orientation) {
  pair<int, int> ans = {0, 1};

  if (orientation == 'S') ans = {0, -1};
  else if (orientation == 'W') ans = {-1, 0};
  else if (orientation == 'E') ans = {1, 0};

  return ans;
}

char getCurrentOrientation(pair<int, int> dir) {
  char orientation = 'N';

  if (dir == pair<int, int>{0, -1}) orientation = 'S';
  else if (dir == pair<int, int>{-1, 0}) orientation = 'W';
  else if (dir == pair<int, int>{1, 0}) orientation = 'E';

  return orientation;
}

void turnLeft(pair<int, int> &dir) {
  if (dir == pair<int, int>{0, 1}) dir = {-1, 0};
  else if (dir == pair<int, int>{-1, 0}) dir = {0, -1};
  else if (dir == pair<int, int>{0, -1}) dir = {1, 0};
  else if (dir == pair<int, int>{1, 0}) dir = {0, 1};
}

void turnRight(pair<int, int> &dir) {
  if (dir == pair<int, int>{0, 1}) dir = {1, 0};
  else if (dir == pair<int, int>{-1, 0}) dir = {0, 1};
  else if (dir == pair<int, int>{0, -1}) dir = {-1, 0};
  else if (dir == pair<int, int>{1, 0}) dir = {0, -1};
}

void solve(int tt) {
  int maxX, maxY;
  cin >> maxX >> maxY;

  int x, y;
  char orientation;
  set<pair<int, int>> points;
  while (cin >> x >> y >> orientation) {
    bool lost = false;
    string instructions;
    cin >> instructions;

    pair<int, int> dir = getCurrentDirection(orientation);

    for (char l : instructions) {
      if (l == 'L') turnLeft(dir);
      else if (l == 'R') turnRight(dir);
      else if (l == 'F') {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (points.count({nx, ny})) continue;

        x = nx;
        y = ny;

        if (x < 0 || y < 0 || x > maxX || y > maxY) {
          lost = true;
          points.insert({x, y});
          x -= dir.first;
          y -= dir.second;
          break;
        }
      }
    }

    cout << x << " " << y << " " << getCurrentOrientation(dir) << (lost ? " LOST" : "") << endl;

  }

}

int main() {
  int tt = 1;
  if (TESTCASES) cin >> tt;
  for (int t = 1; t <= tt; t++) {
    solve(t);
  }
  return 0;
}
