#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    deque<int> q;
    for (int i = 1; i <= n; i++) {
      q.push_back(i);
    }

    for (int m = 2; q.size() >= m; m++) {
      int qs = q.size();
      for (int i = 1; i <= qs; i++) {
        int curr = q.front();
        q.pop_front();
        if ((i - 1) % m) {
          q.push_back(curr);
        }
      }
    }

    cout << n << ":";
    while (!q.empty()) {
      cout << " " << q.back();
      q.pop_back();
    }
    cout << endl;
  }
  return 0;
}
