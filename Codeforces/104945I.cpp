#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int m, n;
  cin >> m >> n;

  double sumM = 0, sumN = 0;

  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;

    sumM += (x + 1) / 2.0;
  }
  
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    sumN += (x + 1) / 2.0;
  }

  if (sumM == sumN) {
    cout << "TIED" << endl;
  } else {
    cout << (sumM > sumN ? "ALICE" : "BOB") << endl;
  }
  return 0;
}
