#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    char x;
    pair<int, int> start;
    pair<int, int> end;
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> x;
        if (x == '*') {
          visited[i][j] = true;
        } else if (x == 'S') {
          start = {i, j};
        } else if (x == 'F') {
          end = {i, j};
        }
      }
    }

    stack<pair<int, int>> st;
    st.push(start);

    bool ans = false;
    while (!st.empty()) {
      pair<int, int> curr = st.top();
      st.pop();

      int currI = curr.first;
      int currJ = curr.second;

      if (end.first == currI && end.second == currJ) {
        ans = true;
        break;
      }

      if (currI > 0 && !visited[currI - 1][currJ]) {
        visited[currI - 1][currJ] = true;
        st.push({currI - 1, currJ});
      }
      if (currI < n - 1 && !visited[currI + 1][currJ]) {
        visited[currI + 1][currJ] = true;
        st.push({currI + 1, currJ});
      }

      if (currJ > 0 && !visited[currI][currJ - 1]) {
        visited[currI][currJ - 1] = true;
        st.push({currI, currJ - 1});
      }
      if (currJ < m - 1 && !visited[currI][currJ + 1]) {
        visited[currI][currJ + 1] = true;
        st.push({currI, currJ + 1});
      }
    }

    cout << (ans ? "SI\n" : "NO\n");
  }
  return 0;
}
