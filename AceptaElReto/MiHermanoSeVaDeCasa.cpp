#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int w, h, p1, p2;
  while (cin >> w >> h >> p1 >> p2) {
    int aux = min(w, h);
    w = max(w, h);
    h = aux;

    if (h > p1 || h > p2) {
      cout << "NO" << endl;
      continue;
    }
    
    double d = sqrt(pow(w - p2, 2) + pow(h, 2));
    cout << d << endl;

    if (d > p1 || d > p2) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
  }
  return 0;
}
