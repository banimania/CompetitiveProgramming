#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j) {
  return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

vector<pair<int, int>> knightMoves = {{2, 1}, {1, 2}, {-2, 1}, {1, -2}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}};
void check(int i, int j, vector<vector<bool>> &attack, vector<vector<char>> &board) {
  char type = tolower(board[i][j]);

  if (type == 'p') {
    if (board[i][j] == 'P') {
      if (i != 0) {
        if (j > 0) attack[i - 1][j - 1] = true;
        if (j < 7) attack[i - 1][j + 1] = true;
      }
    } else {
      if (i != 7) {
        if (j > 0) attack[i + 1][j - 1] = true;
        if (j < 7) attack[i + 1][j + 1] = true;
      }
    }
  } else if (type == 'n') {
    for (int dir = 0; dir < knightMoves.size(); dir++) {
      int newI = i + knightMoves[dir].first;
      int newJ = j + knightMoves[dir].second;

      if (isValid(newI, newJ)) attack[newI][newJ] = true;
    }
  } else if (type == 'r') {
    for (int x = i + 1; isValid(x, j); x++) {
      attack[x][j] = true;
      if (board[x][j] != ' ') break;
    }
    for (int x = i - 1; isValid(x, j); x--) {
      attack[x][j] = true;
      if (board[x][j] != ' ') break;
    }
    for (int x = j + 1; isValid(i, x); x++) {
      attack[i][x] = true;
      if (board[i][x] != ' ') break;
    }
    for (int x = j - 1; isValid(i, x); x--) {
      attack[i][x] = true;
      if (board[i][x] != ' ') break;
    }
  } else if (type == 'b') {
    for (int x = 1; isValid(i + x, j + x); x++) {
      attack[i + x][j + x] = true;
      if (board[i + x][j + x] != ' ') break;
    }
    for (int x = 1; isValid(i - x, j + x); x++) {
      attack[i - x][j + x] = true;
      if (board[i - x][j + x] != ' ') break;
    }
    for (int x = 1; isValid(i + x, j - x); x++) {
      attack[i + x][j - x] = true;
      if (board[i + x][j - x] != ' ') break;
    }
    for (int x = 1; isValid(i - x, j - x); x++) {
      attack[i - x][j - x] = true;
      if (board[i - x][j - x] != ' ') break;
    }
  } else if (type == 'q') {
    for (int x = i + 1; isValid(x, j); x++) {
      attack[x][j] = true;
      if (board[x][j] != ' ') break;
    }
    for (int x = i - 1; isValid(x, j); x--) {
      attack[x][j] = true;
      if (board[x][j] != ' ') break;
    }
    for (int x = j + 1; isValid(i, x); x++) {
      attack[i][x] = true;
      if (board[i][x] != ' ') break;
    }
    for (int x = j - 1; isValid(i, x); x--) {
      attack[i][x] = true;
      if (board[i][x] != ' ') break;
    }
    for (int x = 1; isValid(i + x, j + x); x++) {
      attack[i + x][j + x] = true;
      if (board[i + x][j + x] != ' ') break;
    }
    for (int x = 1; isValid(i - x, j + x); x++) {
      attack[i - x][j + x] = true;
      if (board[i - x][j + x] != ' ') break;
    }
    for (int x = 1; isValid(i + x, j - x); x++) {
      attack[i + x][j - x] = true;
      if (board[i + x][j - x] != ' ') break;
    }
    for (int x = 1; isValid(i - x, j - x); x++) {
      attack[i - x][j - x] = true;
      if (board[i - x][j - x] != ' ') break;
    }
  } else if (type == 'k') {
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (isValid(i + di, j + dj)) attack[i + di][j + dj] = true;
      }
    }
  }
}

void solve() {
  string s;
  cin >> s;

  vector<string> filas(8);
  string curr = "";

  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '/') {
      filas[cnt] = curr;
      cnt++;
      curr = "";
    } else {
      curr += s[i];
    }
  }

  filas[cnt] += curr;

  vector<vector<char>> board(8, vector<char>(8));
  for (int i = 0; i < 8; i++) {
    int cPos = 0;
    for (int j = 0; j < filas[i].size(); j++) {
      if (isdigit(filas[i][j])) {
        int num = filas[i][j] - '0';

        for (int k = 0; k < num; k++) {
          board[i][cPos] = ' ';
          cPos++;
        }
      } else {
        board[i][cPos] = filas[i][j];
        cPos++;
      }
    }
  }

  vector<vector<bool>> attack(8, vector<bool>(8, false));

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] != ' ') {
        attack[i][j] = true;
        check(i, j, attack, board);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (!attack[i][j]) ans++;
    }
  }

  // for (int i = 0; i < 8; i++) {
  //   for (int j = 0; j < 8; j++) {
  //     cout << board[i][j];
  //   }
  //   cout << endl;
  // }

  // for (int i = 0; i < 8; i++) {
  //   for (int j = 0; j < 8; j++) {
  //     cout << (attack[i][j] ? "X" : " ");
  //   }
  //   cout << endl;
  // }

  cout << ans << endl;
  // cout << "--" << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
