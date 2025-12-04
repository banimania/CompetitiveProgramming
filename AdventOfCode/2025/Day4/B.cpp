#include <bits/stdc++.h>
using namespace std;

// vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

typedef long long ll;

void simulate(vector<string> &a) {
  vector<string> newA(a.begin(), a.end());
  int n = a.size();
  int m  = a[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '@') {
        int adj = 0;
        for (auto [dI, dJ] : dirs) {
          int newI = i + dI;
          int newJ = j + dJ;

          if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && a[newI][newJ] == '@') {
            adj++;
          }
        }

        if (adj < 4) {
          newA[i][j] = '.';
        }
      }
    }
  }

  a = newA;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll ans = 0;

  vector<string> a;
  string line;
  ll old = 0;
  while (getline(cin, line)) {
    for (int i = 0; i < line.size(); i++) if (line[i] == '@') old++;
    a.push_back(line);
  }
  cout << "\n";
  for (int i = 0; i < 1000; i++) simulate(a);

  int newP = 0;
  int n = a.size();
  int m  = a[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
      if (a[i][j] == '@') newP++;
    }
    cout << "\n";
  }
  cout << old - newP << "\n";

  return 0;
}
