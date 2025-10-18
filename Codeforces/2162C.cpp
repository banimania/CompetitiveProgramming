#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string toBinary(int n) {
  int x = 0;
  string a = "";
  while (n > 0) {
    a.push_back((n % 2) + '0');
    n /= 2;
    x++;
  }

  reverse(a.begin(), a.end());
  return a;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  string bA = toBinary(a);
  string bB = toBinary(b);

  if (bB.size() > bA.size()) {
    cout << -1 << endl;
    return;
  }

  while (bB.size() < bA.size()) {
    bB = "0" + bB;
  }

  vector<ll> ops;
  for (ll i = 0; i < bA.size(); i++) {
    if (bA[bA.size() - i - 1] != bB[bA.size() - i - 1]) {
      ops.push_back((1 << i));
      a ^= (1 << i);
    }
  }

  cout << ops.size() << endl;
  if (!ops.empty()) {
    for (int i = 0; i < ops.size(); i++) {
      cout << ops[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
