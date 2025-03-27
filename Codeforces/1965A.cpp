#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  set<int> a;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    a.insert(x);
  }

  int dec = -1;
  int prev = 0;
  int cnt = 0;
  for (int i : a) {
    if (prev + 1 != i) {
      dec = cnt % 2;
      break;
    }
    prev = i;
    cnt++;
  }

  if (dec == -1) cout << (a.size() % 2 == 0 ? "Bob" : "Alice") << endl;
  else cout << (dec == 1 ? "Bob" : "Alice") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
