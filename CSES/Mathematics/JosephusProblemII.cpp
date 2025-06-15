#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  int cnt = 1;
  while (!q.empty()) {
    int e = q.front();
    q.pop();
    if (cnt % (k + 1) == 0) {
      cout << e << " ";
    } else q.push(e);
    cnt++;
  }

  cout << endl;
  return 0;
}
