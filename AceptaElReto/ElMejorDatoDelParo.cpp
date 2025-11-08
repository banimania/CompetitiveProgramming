#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    stack<int> st;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];

      while (!st.empty() && v[st.top()] <= v[i]) {
        st.pop();
      }

      if (st.empty()) {
        cout << 0;
      } else {
        cout << (i - st.top());
      }

      st.push(i);

      cout << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
  }

  return 0;
}
