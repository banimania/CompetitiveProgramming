#include <bits/stdc++.h>
using namespace std;

pair<int, int> decodeDir(int dir) {
  if (dir == 0) return {0, 1};
  else if (dir == 1) return {1, 0};
  else if (dir == 2) return {0, -1};
  return {-1, 0};
}

bool solve(int &currI, int &currJ, int &currDir, vector<vector<bool>> &visited) {
  if (currI == visited.size() - 1 && currJ == visited.size() - 1) {
    string end;
    cin >> end;
    return true;
  }

  int originalDir = currDir;
  int ignore;
  for (int i = 0; i < 4; i++) {
    int targetDir = (originalDir + i) % 4;
    int nextFree;
    bool done = false;
    while (currDir != targetDir) {
      cout << "D" << endl;
      cin >> nextFree;
      currDir = (currDir + 1) % 4;
      done = true;
    }

    if (!done) cin >> nextFree;
    int dir = targetDir;

    if (nextFree > 0) {
      int nextI = currI + decodeDir(currDir).first;
      int nextJ = currJ + decodeDir(currDir).second;

      int oldI = currI;
      int oldJ = currJ;

      if (nextI >= visited.size() || nextJ >= visited.size() || nextI < 0 || nextJ < 0) continue;

      if (!visited[nextI][nextJ]) {
        currI = nextI;
        currJ = nextJ;
        visited[currI][currJ] = true;

        cout << "A" << endl;

        if (solve(currI, currJ, currDir, visited)) {
          return true;
        } else {
          nextI = currI + decodeDir(currDir).first;
          nextJ = currJ + decodeDir(currDir).second;

          while (nextI != oldI || nextJ != oldJ) {
            cout << "D" << endl;
            cin >> ignore;
            currDir = (currDir + 1) % 4;

            nextI = currI + decodeDir(currDir).first;
            nextJ = currJ + decodeDir(currDir).second;
          }

          cout << "A" << endl;
          cin >> ignore;
          currI = oldI;
          currJ = oldJ;
        }
      }
    }
    
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  int i = 0, j = 0, dir = 0;
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  visited[0][0] = true;
  solve(i, j, dir, visited);

  return 0;
}
