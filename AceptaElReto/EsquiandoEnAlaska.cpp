#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> alturas(n), longitudes(n);

    for (int i = 0; i < n; i++) {
      cin >> alturas[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> longitudes[i];
    }

    sort(alturas.begin(), alturas.end());
    sort(longitudes.begin(), longitudes.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
      ans += abs(alturas[i] - longitudes[i]);
    }

    cout << ans << endl;
  }
  return 0;
}
