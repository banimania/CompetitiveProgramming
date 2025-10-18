#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

void solve() {
  int n, m, k, H;
  cin >> n >> m >> k >> H;

  vector<bool> possible(n);
  vector<int> heights(n);
  for (int i = 0; i < n; i++) cin >> heights[i];

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m && !possible[i]; j++) {
      for (int l = 1; l <= m; l++) {
        if (j == l) continue;

        if (j * k + heights[i] == l * k + H) {
          possible[i] = true;
          break;
        }
      }
    }

  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (possible[i]) ans++;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
