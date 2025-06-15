#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  int cnt = 1;
  while (!q.empty()) {
    int e = q.front();
    q.pop();
    if (cnt % 2 == 0) {
      cout << e << " ";
    } else q.push(e);
    cnt++;
  }

  cout << endl;
  return 0;
}
