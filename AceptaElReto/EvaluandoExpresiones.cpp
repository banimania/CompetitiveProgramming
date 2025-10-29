#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  while (getline(cin, line)) {
    stack<int> st;
    queue<int> q;
    bool errorSt = false;
    bool errorQ = false;
    for (int i = 0; i < line.size(); i++) {
      if (errorSt && errorQ) break;
      if (isdigit(line[i])) {
        if (!errorSt) {
          st.push(line[i] - '0');
        }
        if (!errorQ) {
          q.push(line[i] - '0');
        }
      } else {
        if (!errorSt) {
          int b = st.top();
          st.pop();
          int a = st.top();
          st.pop();
          if (line[i] == '+') {
            st.push(a + b);
          } else if (line[i] == '-') {
            st.push(a - b);
          } else if (line[i] == '*') {
            st.push(a * b);
          } else {
            if (b == 0) {
              errorSt = true;
            } else {
              st.push(a / b);
            }
          }
        }

        if (!errorQ) {
          int b = q.front();
          q.pop();
          int a = q.front();
          q.pop();
          if (line[i] == '+') {
            q.push(a + b);
          } else if (line[i] == '-') {
            q.push(a - b);
          } else if (line[i] == '*') {
            q.push(a * b);
          } else {
            if (b == 0) {
              errorQ = true;
            } else {
              q.push(a / b);
            }
          }
        }
      }
    }
    
    if (errorSt) {
      cout << "ERROR";
    } else {
      cout << st.top();
    }

    if ((errorSt && !errorQ) || (errorQ && !errorSt) || (!errorQ && !errorSt && st.top() != q.front())) {
      cout << " != ";
    } else {
      cout << " = ";
    }

    if (errorQ) {
      cout << "ERROR";
    } else {
      cout << q.front();
    }
    cout << "\n";
  }

  return 0;
}
