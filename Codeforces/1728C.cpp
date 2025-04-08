#include <bits/stdc++.h>
using namespace std;

int f(int a) {
  int cnt = 0;

  while (a > 0) {
    cnt++;
    a /= 10;
  }

  return cnt;
}

void solve() {
  int n;
  cin >> n;

  priority_queue<int> pq1, pq2;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    pq1.push(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    pq2.push(x);
  }

  int ans = 0;

  while (!pq1.empty()) {
    if (pq1.top() == pq2.top()) {
      pq1.pop();
      pq2.pop();
    } else {
      ans++;
      if (pq1.top() > pq2.top()) {
        int l = f(pq1.top());
        pq1.pop();
        pq1.push(l);
      } else {
        int l = f(pq2.top());
        pq2.pop();
        pq2.push(l);
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
