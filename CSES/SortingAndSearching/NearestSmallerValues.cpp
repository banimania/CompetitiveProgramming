#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  stack<int> st;
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }

    if (!st.empty()) {
      ans[i] = st.top();
    }

    st.push(i);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << (i == n - 1 ? "" : " ");
  }
  cout << "\n";
  return 0;
}
