// TODO: FIX
#include <bits/stdc++.h>
using namespace std;

/*void solve(int i, int j, vector<char> &diag1, vector<char> &diag2, vector<bool> &fil, vector<bool> &col, vector<vector<int>> &nums, int &score, int &placedQ, int &placedR, int q, int r, int &best, int n) {
  int remainingPieces = q - placedQ + r - placedR;
  if (n - i < remainingPieces) return;
  if (placedR == r && placedQ == q) {
    best = max(best, score);
    return;
  }

  if (i == n) return;

  int diagN1 = (i - j);
  if (j > i) {
    diagN1 = 2 * n - 1 + (i - j);
  }
  int diagN2 = i + j;

  int nextI = i + ((j + 1) / n);
  int nextJ = (j + 1) % n;
  if (fil[i]) {
    solve(i + 1, 0, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);
    return;
  }
  if (col[j] || diag1[diagN1] == 'Q' || diag2[diagN2] == 'Q') {
    solve(nextI, nextJ, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);
    return;
  }

  if (placedR < r && diag1[diagN1] != 'Q' && diag2[diagN2] != 'Q') {
    fil[i] = true;
    col[j] = true;
    diag1[diagN1] = 'R';
    diag2[diagN2] = 'R';

    score += nums[i][j];
    placedR++;

    solve(i + 1, 0, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);

    placedR--;
    score -= nums[i][j];
    diag1[diagN1] = 'X';
    diag2[diagN2] = 'X';
    fil[i] = false;
    col[j] = false;
  }

  if (placedQ < q && diag1[diagN1] == 'X' && diag2[diagN2] == 'X') {
    fil[i] = true;
    col[j] = true;
    diag1[diagN1] = 'Q';
    diag2[diagN2] = 'Q';

    score += nums[i][j];
    placedQ++;

    solve(i + 1, 0, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);

    placedQ--;
    score -= nums[i][j];
    fil[i] = false;
    col[j] = false;
    diag1[diagN1] = 'X';
    diag2[diagN2] = 'X';
  }

  solve(nextI, nextJ, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);
}*/

void solve(int i, vector<char> &diag1, vector<char> &diag2, vector<bool> &fil, vector<bool> &col, vector<vector<int>> &nums, int &score, int &placedQ, int &placedR, int q, int r, int &best, int n) {
  int remainingPieces = q - placedQ + r - placedR;
  if (n - i < remainingPieces) return;
  if (placedR == r && placedQ == q) {
    best = max(best, score);
    return;
  }

  if (i == n) return;

  for (int j = 0; j < n; j++) {
    if (col[j]) continue;

    int diagN1 = (i - j);
    if (j > i) {
      diagN1 = 2 * n - 1 + (i - j);
    }
    int diagN2 = i + j;

    if (placedR < r && diag1[diagN1] != 'Q' && diag2[diagN2] != 'Q') {
      fil[i] = true;
      col[j] = true;
      diag1[diagN1] = 'R';
      diag2[diagN2] = 'R';

      score += nums[i][j];
      placedR++;

      solve(i + 1, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);

      placedR--;
      score -= nums[i][j];
      diag1[diagN1] = 'X';
      diag2[diagN2] = 'X';
      fil[i] = false;
      col[j] = false;
    }

    if (placedQ < q && diag1[diagN1] == 'X' && diag2[diagN2] == 'X') {
      fil[i] = true;
      col[j] = true;
      diag1[diagN1] = 'Q';
      diag2[diagN2] = 'Q';

      score += nums[i][j];
      placedQ++;

      solve(i + 1, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);

      placedQ--;
      score -= nums[i][j];
      fil[i] = false;
      col[j] = false;
      diag1[diagN1] = 'X';
      diag2[diagN2] = 'X';
    }
  }

  solve(i + 1, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int q, r;
  while (cin >> q >> r) {
    int n = q + r;
    vector<vector<int>> nums(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> nums[i][j];
      }
    }

    vector<char> diag1(2 * n - 1, 'X');
    vector<char> diag2(2 * n - 1, 'X');
    vector<bool> fil(n, false);
    vector<bool> col(n, false);

    int score = 0;
    int placedQ = 0;
    int placedR = 0;
    int best = 0;

    solve(0, diag1, diag2, fil, col, nums, score, placedQ, placedR, q, r, best, n);

    cout << best << "\n";
  }
  return 0;
}
