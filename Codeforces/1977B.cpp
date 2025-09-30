#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll x;
  cin >> x;
  // cout << "x = " << x << endl;

  vector<int> ans(32);

  int s = 0;
  while (x > 0) {
    ans[s] = (x % 2);

    x /= 2;
    s++;
  }

  bool valid = false;
  while (!valid) {

    for (int i = 30; i > 0; i--) {
      if (ans[i] == 1 && ans[i - 1] == 1) {
        int j = i;
        while (j > 0 && ans[j - 1] == 1) j--;

        ans[i + 1] = 1;
        ans[j] = -1;

        for (int k = i; k > j; k--) {
          ans[k] = 0;
        }
      }
    }


    valid = true;
    for (int i = 0; i < 31; i++) {
      if (ans[i] == 1 && ans[i + 1] == -1) {
        ans[i + 1] = 0;
        ans[i] = -1;
      } else if (ans[i] == -1 && ans[i + 1] == 1) {
        ans[i + 1] = 0;
        ans[i] = 1;
      }
      if (ans[i] != 0 && ans[i + 1] != 0) {
        valid = false;
        break;
      }

    }
  }


  cout << 32 << endl;
  for (int i = 0; i < 32; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
