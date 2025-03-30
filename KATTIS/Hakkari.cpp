#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  char x;
  vector<pair<int, int>> sol;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;

      if (x == '*') {
        sol.push_back({i + 1, j + 1});
      }
    }
  }

  cout << sol.size() << endl;
  for (int i = 0; i < sol.size(); i++) {
    cout << sol[i].first << " " << sol[i].second << endl;
  }
  return 0;
}
