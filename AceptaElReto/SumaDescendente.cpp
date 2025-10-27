#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ll> pow10(10);
  pow10[0] = 1;
  for (int i = 1; i < 10; i++) pow10[i] = pow10[i - 1] * 10;

  string str;
  while (cin >> str) {
    if (str == "0") break;

    int n = str.size();
    ll ans = 0;

    for (int i = 0; i < n; i++) {
      ans += (str[i] - '0') * (i + 1) * pow10[n - i - 1];
    }

    cout << ans << '\n';
  }
  return 0;
}
