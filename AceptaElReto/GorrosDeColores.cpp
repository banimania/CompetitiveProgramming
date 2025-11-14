#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int n = s.size();

    int res = n / 2;

    for (int i = 0; i < n; i += 2) {
      if (s[i] == s[i + 1]) {
        res++;
      }
    }
    cout << res << "\n";
  }

  return 0;
}
