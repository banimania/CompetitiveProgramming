#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 0

typedef long long ll;

void solve() {
  int n;
  while (cin >> n && n) {
    int currVeces = 0;
    int curr;
    cin >> curr;
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
      int x;
      cin >> x;

      if (curr >= x) {
        currVeces++;
      } else {
        ans = max(ans, currVeces + 1);
        curr = x;
        currVeces = 1;
      }
      ans = max(ans, currVeces);
    }

    cout << ans << endl;
  }
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
