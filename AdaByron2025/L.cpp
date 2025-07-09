#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  priority_queue<int> pq_low;
  priority_queue<int, vector<int>, greater<int>> pq_high;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (i == 0) ans++;
    else ans += (x > pq_low.top());

    if (pq_low.empty() || x <= pq_low.top()) {
      pq_low.push(x);
    } else {
      pq_high.push(x);
    }

    while (pq_high.size() > pq_low.size()) {
      pq_low.push(pq_high.top());
      pq_high.pop();
    }

    while (pq_low.size() > pq_high.size() + 1) {
      pq_high.push(pq_low.top());
      pq_low.pop();
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
