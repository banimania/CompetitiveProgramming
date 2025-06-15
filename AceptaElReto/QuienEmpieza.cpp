#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    if (!n && !k) break;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      q.push(i);
    }

    int cnt = 1;
    while (q.size() != 1) {
      int e = q.front();
      q.pop();

      if (cnt % (k + 1)) {
        q.push(e);
      }
      cnt++;
    }
    cout << q.front() << endl;
  }
  return 0;
}
