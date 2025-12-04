#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // cin.tie(0);
  // ios::sync_with_stdio(0);

  ll ans = 0;

  string line;
  while (getline(cin, line)) {
    ll maxC = 0;
    for (int i = 0; i < (int) line.size() - 1; i++) {
      ll curr = (line[i] - '0') * 10LL;
      for (int j = i + 1; j < (int) line.size(); j++) {
        maxC = max(maxC, curr + (line[j] - '0'));
      }
    }
    cout << "max = " << maxC << endl;
    ans += maxC;
  }

  cout << ans << "\n";

  return 0;
}
