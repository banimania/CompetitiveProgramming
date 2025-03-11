#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    int m; cin >> m;
    vector<int> grados(m);
    for (int i = 0; i < n; i++) {
      int a, b; cin >> a >> b; a--, b--;
      grados[a]++;
      grados[b]++;
    }
    int impar = 0;
    for (int i = 0; i < m; i++) {
      if (grados[i]%2) impar++;
    }
    cout << ((impar == 0 || impar==2) ? "SI" : "NO") << endl;
  }

  return 0;
}
