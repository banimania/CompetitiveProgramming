#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  while (getline(cin, line)) {
    stack<char> st;

    bool valid = true;
    
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '(') {
        st.push('(');
      } else if (line[i] == ')') {
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else valid = false;
      } else if (line[i] == '[') {
        st.push('[');
      } else if (line[i] == ']') {
        if (!st.empty() && st.top() == '[') {
          st.pop();
        } else valid = false;
      } else if (line[i] == '{') {
        st.push('{');
      } else if (line[i] == '}') {
        if (!st.empty() && st.top() == '{') {
          st.pop();
        } else valid = false;
      }
    }

    valid &= st.empty();

    cout << (valid ? "YES" : "NO") << "\n";
  }
  return 0;
}
