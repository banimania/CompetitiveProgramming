#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<vector<char>> a(2, vector<char>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> visited(2, vector<int>(n));
  stack<pair<int, int>> st;
  st.push({0, 0});

  while (!st.empty()) {
    pair<int, int> curr = st.top();
    st.pop();

    if (curr.first == 1 && curr.second == n - 1) {
      cout << "YES" << endl;
      return;
    }

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        pair<int, int> newPos = {curr.first + i, curr.second + j};
        
        if (newPos.second < 0 || newPos.second >= n || newPos.first < 0 || newPos.first >= 2) continue;

        if (a[newPos.first][newPos.second] == '0' && !visited[newPos.first][newPos.second]) {
          st.push(newPos);
          visited[newPos.first][newPos.second] = true;

        }
      }
    }
  }

  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
