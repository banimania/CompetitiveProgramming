#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string line;
    cin >> line;

    vector<bool> visited(line.size(), false);

    stack<int> st;
    st.push(0);
    while (!st.empty()) {
      int curr = st.top();
      st.pop();

      int next = (curr + (line[curr] - '0')) % line.size();

      if (!visited[next]) {
        visited[next] = true;
        st.push(next);
      }
    }

    bool salt = true;
    for (int i = 0; i < line.size(); i++) {
      if (!visited[i]) salt = false;
    }

    cout << (salt ? "SALTARINES" : "NORMALES") << "\n";
  }

  return 0;
}
