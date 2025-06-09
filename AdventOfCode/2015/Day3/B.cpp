#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> dirs = {{'^', {1, 0}}, {'v', {-1, 0}}, {'<', {0, -1}}, {'>', {0, 1}}};
int main() {
  string s;
  cin >> s;

  int i = 0, j = 0, i2 = 0, j2 = 0;

  set<pair<int, int>> visited = {{i, j}};

  for (int c = 0; c < s.size(); c++) {
    (c % 2 == 0 ? i : i2) += dirs[s[c]].first;
    (c % 2 == 0 ? j : j2) += dirs[s[c]].second;
    visited.insert(c % 2 == 0 ? pair<int, int>{i, j} : pair<int, int>{i2, j2});
  }

  cout << visited.size() << endl;
  return 0;
}
