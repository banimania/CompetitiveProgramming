#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k;
  cin >> k;

  int ans = 0;

  stack<int> st;
  for (int i = 0; i < 12; i++) {
    int x;
    cin >> x;

    if (st.empty()) {
      st.push(x);
      continue;
    }

    while (!st.empty() && x < st.top()) {
      st.pop();
      ans++;
    }

    if (x > st.top()) {
      st.push(x);
      continue;
    }

  }

  cout << k << " " << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
