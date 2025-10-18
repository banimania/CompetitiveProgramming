#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll n;
  while (cin >> n && n) {
    ll sq = n * n;
    string sqStr = to_string(sq);

    bool ans = false;

    for (int i = 0; i <= sqStr.size(); i++) {
      string fs = sqStr.substr(0, i);
      string ss = sqStr.substr(i, sqStr.size() - i);

      ll f = fs.empty() ? 0 : stoll(fs);
      ll s = ss.empty() ? 0 : stoll(ss);

      if (s == 0) continue;
      if (f + s == n) {
        ans = true;
        break;
      }
    }

    cout << (ans ? "SI" : "NO") << endl;
  }

  return 0;
}
