#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<pair<int, int>> act(n);
    for (int i = 0; i < n; i++) {
      cin >> act[i].first >> act[i].second;
    }

    sort(act.begin(), act.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(0);

    for (int i = 0; i < n; i++) {
      int start = act[i].first, end = act[i].second;

      if (!pq.empty() && act[i].first >= pq.top()) {
        pq.pop();
      }

      pq.push(act[i].second);
    }

    cout << pq.size() - 1 << endl;
  }
  return 0;
}
