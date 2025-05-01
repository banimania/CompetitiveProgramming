#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    int ans = 0;
    stack<char> st;

    for (int i = 0; i < line.size(); i++) {
      if (line[i] == 'V') {
        if (!st.empty() && st.top() == 'A') {
          st.pop();
          if (!st.empty() && st.top() == 'R') {
            st.pop();
            ans++;
          } else {
            st.push('A');
            st.push('V');
          }
        } else st.push('V');
      } else st.push(line[i]);
    }

    cout << ans << endl;
  }
}
