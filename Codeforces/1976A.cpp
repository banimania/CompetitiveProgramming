#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (is_sorted(s.begin(), s.end())) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
