#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int a, b; cin >> a >> b;
      sum += abs(a-b);
    }
    cout << sum << endl;
  }

  return 0;
}
