#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Estado {
  int i, j, pasos;
};

struct Estado2 {
  int i, j;
  char facing;
};

// U = 0
// D = 1
// R = 2
// L = 3
int faceToInt (char face) {
  if (face == 'U') return 0;
  if (face == 'D') return 1;
  if (face == 'R') return 2;
  return 3;
}

char rotateRight(char face) {
  if (face == 'U') return 'R';
  if (face == 'D') return 'L';
  if (face == 'R') return 'D';
  return 'U';
}

char rotateLeft(char face) {
  if (face == 'U') return 'L';
  if (face == 'D') return 'R';
  if (face == 'R') return 'U';
  return 'D';
}

char rotateBackwards(char face) {
  if (face == 'D') return 'U';
  if (face == 'U') return 'D';
  if (face == 'L') return 'R';
  return 'L';
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  while (cin >> m >> n) {
    vector<vector<char>> laberinto(n, vector<char>(m));
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> laberinto[i][j];
        if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && laberinto[i][j] == '.') {
          start = {i, j};
        }
      }
    }

    queue<Estado> q;
    q.push({start.first, start.second, 0});
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[start.first][start.second] = true;
    ll shortest = LLONG_MAX;
    while (!q.empty()) {
      Estado curr = q.front();
      q.pop();
      int i = curr.i;
      int j = curr.j;
      int pasos = curr.pasos;

      if (laberinto[i][j] == 'T') {
        shortest = pasos;
        break;
      }

      if (i > 0 && laberinto[i - 1][j] != '#' && !visited[i - 1][j]) {
        q.push({i - 1, j, pasos + 1});
        visited[i - 1][j] = true;
      }

      if (j > 0 && laberinto[i][j - 1] != '#' && !visited[i][j - 1]) {
        q.push({i, j - 1, pasos + 1});
        visited[i][j - 1] = true;
      }

      if (i < n - 1 && laberinto[i + 1][j] != '#' && !visited[i + 1][j]) {
        q.push({i + 1, j, pasos + 1});
        visited[i + 1][j] = true;
      }

      if (j < m - 1 && laberinto[i][j + 1] != '#' && !visited[i][j + 1]) {
        q.push({i, j + 1, pasos + 1});
        visited[i][j + 1] = true;
      }
    }

    if (shortest == LLONG_MAX) {
      cout << "IMPOSIBLE\n";
      continue;
    }

    vector<vector<vector<bool>>> visited2(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    Estado2 curr = {start.first, start.second, 'U'};
    int pasos = 0;
    bool inf = false;
    while (true) {
      int i = curr.i;
      int j = curr.j;
      char facing = curr.facing;

      // cout << i << " " << j << " " << facing << " pasos = " << pasos << endl;
      if (laberinto[i][j] == 'T') {
        break;
      }

      if (visited2[i][j][faceToInt(facing)]) {
        inf = true;
        break;
      }

      visited2[i][j][faceToInt(facing)] = true;

      int rightI, rightJ;
      if (facing == 'U') {
        rightI = i;
        rightJ = j + 1;
      } else if (facing == 'D') {
        rightI = i;
        rightJ = j - 1;
      } else if (facing == 'R') {
        rightI = i + 1;
        rightJ = j;
      } else {
        rightI = i - 1;
        rightJ = j;
      }

      bool canGoRight = (rightI >= 0 && rightI < n && rightJ >= 0 && rightJ < m && laberinto[rightI][rightJ] != '#');
      // cout << "can go right = " << canGoRight << endl;
      if (canGoRight) {
        curr.i = rightI;
        curr.j = rightJ;
        curr.facing = rotateRight(curr.facing);
        pasos++;
        continue;
      }

      int nextI, nextJ;
      if (facing == 'U') {
        nextI = i - 1;
        nextJ = j;
      } else if (facing == 'D') {
        nextI = i + 1;
        nextJ = j;
      } else if (facing == 'R') {
        nextI = i;
        nextJ = j + 1;
      } else {
        nextI = i;
        nextJ = j - 1;
      }

      bool canGoNext = (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m && laberinto[nextI][nextJ] != '#');
      // cout << "can go next = " << canGoNext << endl;
      if (canGoNext) {
        curr.i = nextI;
        curr.j = nextJ;
        pasos++;
        continue;
      }

      int leftI, leftJ;
      if (facing == 'U') {
        leftI = i;
        leftJ = j - 1;
      } else if (facing == 'D') {
        leftI = i;
        leftJ = j + 1;
      } else if (facing == 'R') {
        leftI = i - 1;
        leftJ = j;
      } else {
        leftI = i + 1;
        leftJ = j;
      }

      bool canGoLeft = (leftI >= 0 && leftI < n && leftJ >= 0 && leftJ < m && laberinto[leftI][leftJ] != '#');
      // cout << "can go left = " << canGoLeft << endl;
      if (canGoLeft) {
        curr.i = leftI;
        curr.j = leftJ;
        curr.facing = rotateLeft(curr.facing);
        pasos++;
        continue;
      }

      int backI, backJ;
      if (facing == 'U') {
        backI = i + 1;
        backJ = j;
      } else if (facing == 'D') {
        backI = i - 1;
        backJ = j;
      } else if (facing == 'R') {
        backI = i;
        backJ = j - 1;
      } else {
        backI = i;
        backJ = j + 1;
      }

      bool canGoBack = (backI >= 0 && backI < n && backJ >= 0 && backJ < m && laberinto[backI][backJ] != '#');
      // cout << "can go back = " << canGoLeft << endl;
      if (canGoBack) {
        curr.i = backI;
        curr.j = backJ;
        curr.facing = rotateBackwards(curr.facing);
        pasos++;
        continue;
      }
    }

    if (inf) {
      cout << "INF\n";
    } else if (pasos == shortest) {
      cout << "IGUAL\n";
    } else {
      cout << (pasos - shortest) << "\n";
    }
  }
  return 0;
}
