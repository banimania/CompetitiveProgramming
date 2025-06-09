#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> dirs = {{'^', {1, 0}}, {'v', {-1, 0}}, {'<', {0, -1}}, {'>', {0, 1}}};
int main() {
  string s;
  cin >> s;

  int i = 0, j = 0;

  set<pair<int, int>> visited = {{i, j}};

  for (int c : s) {
    i += dirs[c].first;
    j += dirs[c].second;

    visited.insert({i, j});
  }

  cout << visited.size() << endl;
  return 0;
}
