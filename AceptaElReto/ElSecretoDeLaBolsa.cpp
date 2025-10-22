#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int sc;
    cin >> sc;

    string s;
    cin >> s;

    int ini = 0, curr = 0;
    int ans = 0;
    for (int fin = 0; fin < s.size(); fin++) {
      curr += (s[fin] - '0');

      while (curr > sc) {
        if (ini == fin) break;
        curr -= (s[ini] - '0');
        ini++;
      }

      if (curr == sc) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
