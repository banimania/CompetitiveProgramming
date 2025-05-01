#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, L;
  cin >> n >> m >> L;

  vector<pair<int, int>> hurdles(n);
  for (int i = 0; i < n; i++) {
    cin >> hurdles[i].first >> hurdles[i].second;
  }

  vector<pair<int, int>> powerUps(m);
  for (int i = 0; i < m; i++) {
    cin >> powerUps[i].first >> powerUps[i].second;
  }

  int currentPos = 1;
  int ans = 0;

  priority_queue<int> pq;

  int jp = 1, nextHurdle = 0, nextPowerUp = 0;

  while (currentPos < L) {
    if (nextHurdle >= hurdles.size()) break;

    currentPos = hurdles[nextHurdle].first - 1;
    
    while (nextPowerUp < powerUps.size()) {
      if (currentPos >= powerUps[nextPowerUp].first) {
        pq.push(powerUps[nextPowerUp].second);
        nextPowerUp++;
      } else break;
    }

    while (true) {

      if (jp >= hurdles[nextHurdle].second - hurdles[nextHurdle].first + 2) {
        currentPos = hurdles[nextHurdle].second + 1;
        nextHurdle++;
        break;
      }

      if (!pq.empty()) {
        ans++;
        jp += pq.top();
        pq.pop();
      } else {
        cout << -1 << endl;
        return;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) solve();

  return 0;
}
