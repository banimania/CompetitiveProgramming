#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
      cin >> coins[i];
    }

    int ans = 1;
    int suma = 0;
    for (int i = 0; i < n - 1; i++) {
      if (suma + coins[i] < coins[i + 1]) {
        suma += coins[i];
        ans++;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
