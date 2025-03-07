#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  string a;
  cin >> a;

  int opening = 0, closing = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] == '(') {
      opening++;
    } else if (a[i] == ')') {
      closing++;

      if (opening > 0) {
        closing--;
        opening--;
      }
    }

  }
  
  cout << max(opening, closing) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
