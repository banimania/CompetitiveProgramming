#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n, f, t;
  cin >> n >> f >> t;

  cout << (t % (n + 1)) * f << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
