#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int seg = n % 60;
  int min = (n / 60) % 60;
  int hor = (n / 3600);

  cout << setw(2) << setfill('0') << hor << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << seg << "\n";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
