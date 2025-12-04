#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int lado) {
  if (!lado) return 0;
  return 4LL * lado + 4 * solve(lado / 2LL);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) {
    cout << solve(n) << "\n";
  }

  return 0;
}
