#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
      if (!pq.empty() && pq.top() <= v[i]) {
        int h = pq.top();
        pq.pop();
        pq.push(h + 1);
      } else {
        pq.push(1);
      }
    }
    cout << pq.size() << "\n";
  }
  return 0;
}
