#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, n;
  while (cin >> a >> n) {
    if (!a && !n) break;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ini = 0, fin = n - 1;

    int ans = INT_MAX;
    while (fin > ini) {
      int suma = v[fin] + v[ini];

      if (suma > a) {
        ans = min(ans, suma); 
        fin--;
      } else if (suma < a) {
        ini++;
      } else {
        ans = a;
        break;
      }

    }

    if (ans == INT_MAX) {
      cout << "0\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}
