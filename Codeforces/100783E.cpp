#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w, h, l;
  cin >> n >> w >> h >> l;

  pair<int, int> target;
  vector<vector<char>> grid(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == 'X') {
        target = {i, j};
      }
    }
  }


  return 0;
}
