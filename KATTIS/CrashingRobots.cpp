#include <bits/stdc++.h>
using namespace std;

struct Robot {
  int x, y;
  char dir;
  int id;
};

struct Instruction {
  int id;
  char action;
  int repeat;
};

map<char, pair<int, int>> dirs = {{'N', {1, 0}}, {'S', {-1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}};

map<char, char> turnRight = {{'N', 'E'}, {'E', 'S'}, {'S', 'W'}, {'W', 'N'}};
map<char, char> turnLeft = {{'N', 'W'}, {'W', 'S'}, {'S', 'E'}, {'E', 'N'}};

void solve() {
  int a, b; // tamaño
  cin >> a >> b;

  int n, m; // robots y queries
  cin >> n >> m;

  vector<Robot> robots(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    char dir;
    cin >> x >> y >> dir;

    robots[i] = {x, y, dir, i};
  }

  vector<Instruction> instructions(m);
  for (int i = 0; i < m; i++) {
    int id, repeat;
    char action;

    cin >> id >> action >> repeat;
    id--;

    instructions[i] = {id, action, repeat};
  }

  for (int i = 0; i < m; i++) {
    int id = instructions[i].id;
    char action = instructions[i].action;
    int repeat = instructions[i].repeat;

    for (int j = 0; j < repeat; j++) {
      if (action == 'L') {
        robots[id].dir = turnLeft[robots[id].dir];
      } else if (action == 'R') {
        robots[id].dir = turnRight[robots[id].dir];
      } else {
        robots[id].x += dirs[robots[id].dir].second;
        robots[id].y += dirs[robots[id].dir].first;

        if ((((robots[id].x) > a) || ((robots[id].y) > b)) || (((robots[id].x) <= 0) || ((robots[id].y) <= 0))) {
          cout << "Robot " << robots[id].id + 1 << " crashes into the wall" << endl;
          return;
        }

        for (int i = 0; i < robots.size(); i++) {
          if (robots[id].id == robots[i].id) continue;
          if (robots[id].x == robots[i].x && robots[id].y == robots[i].y) {
            cout << "Robot " << robots[id].id + 1 << " crashes into robot " << robots[i].id + 1 << endl;
            return;
          }
        }
      }
    }
  }

  cout << "OK" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
