#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  int path = -1;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 0) {
      adj[i].push_back(n + 1);
    } else if (x == 1) {
      adj[n + 1].push_back(i);
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
