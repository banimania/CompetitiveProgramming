#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct State {
  int i, j, steps;
};

vector<pair<int, int>> dirs = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int main() {
  int r, c, gr, gc, lr, lc;
  while (cin >> r >> c >> gr >> gc >> lr >> lc) {
    gr--;
    gc--;
    lr--;
    lc--;

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<State> q;
    visited[gr][gc] = true;
    q.push({gr, gc, 0});

    bool found = false;
    while (!q.empty()) {
      State curr = q.front();
      q.pop();

      if (curr.i == lr && curr.j == lc) {
        cout << curr.steps << endl;
        found = true;
        break;
      }

      for (auto [dirI, dirJ] : dirs) {
        int newI = curr.i + dirI;
        int newJ = curr.j + dirJ;

        if (newI >= 0 && newI < r && newJ >= 0 && newJ < c && !visited[newI][newJ]) {
          visited[newI][newJ] = true;
          q.push({newI, newJ, curr.steps + 1});
        }
      }
      
    }

    if (!found) {
      cout << "impossible" << endl;
    }
  }
}
