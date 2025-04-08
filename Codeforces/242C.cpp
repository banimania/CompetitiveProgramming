#include <bits/stdc++.h>
using namespace std;

struct State {
  pair<int, int> pos;
  int moves;
};

int main() {
  int x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;

  int n;
  cin >> n;

  set<pair<int, int>> allowed, visited;
  while (n--) {
    int r, a, b;
    cin >> r >> a >> b;

    for (int i = a; i <= b; i++) {
      allowed.insert({r, i});
    }
  }

  pair<int, int> start = {x0, y0}, end = {x1, y1};

  queue<State> q;
  q.push({start, 0});
  visited.insert(start);

  while (!q.empty()) {
    State current = q.front();
    q.pop();

    if (current.pos == end) {
      cout << current.moves << endl;
      return 0;
    }
    
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        pair<int, int> newPos = {current.pos.first + i, current.pos.second + j};
        if (allowed.count(newPos) && !visited.count(newPos)) {
          visited.insert(newPos);
          q.push({newPos, current.moves + 1});
        }
      }
    }
  }

  cout << -1 << endl;

  return 0;
}
