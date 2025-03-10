#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), nboff(31);

  for (int i = 0; i < n; i++) {
    cin >> a[i];

    for (int j = 0; j <= nboff.size(); j++) {
      if (!(a[i] & (1 << j))) nboff[j]++;
    }
  }

  for (int power = 30; power >= 0 && k > 0; power--) {
    if (k >= nboff[power]) {
      k -= nboff[power];
      for (int i = 0; i < n; i++) {
        a[i] |= (1 << power);
      }
    }
  }

  int andValue = -1;
  for (int i = 0; i < n; i++) {
    andValue &= a[i];
  }

  cout << andValue << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
