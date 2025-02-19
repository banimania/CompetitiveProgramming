#include <bits/stdc++.h>
using namespace std;

int leerArbol(int &ans) {
  int numHijos;
  cin >> numHijos;

  int k = (numHijos == 2);
  int h1 = 0;
  int h2 = 0;
  if (numHijos >= 1) {
    h1 = leerArbol(ans);
  }
  if (numHijos == 2) {
    h2 = leerArbol(ans);
  }

  k += min(h1, h2);

  ans = max(ans, k);
  return k;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int ans = 0;
    leerArbol(ans);

    cout << ans << endl;
  }
  return 0;
}
