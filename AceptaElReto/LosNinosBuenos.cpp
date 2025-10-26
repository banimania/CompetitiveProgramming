#include <bits/stdc++.h>
using namespace std;

struct Nino {
  int b;
  int p;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<Nino> ninos(n);
    for (int i = 0; i < n; i++) {
      cin >> ninos[i].b >> ninos[i].p;
    }

    sort(ninos.begin(), ninos.end(), [](const Nino &a, const Nino &b) {
      if (a.b == b.b) return a.p < b.p;
      return a.b > b.b;
    });

    for (int i = 0; i < n; i++) {
      cout << ninos[i].b << " " << ninos[i].p << "\n";
    }
    cout << "\n";
  }

  return 0;
}
