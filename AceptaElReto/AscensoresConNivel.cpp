#include <bits/stdc++.h>
using namespace std;

struct Ascensor {
  int ini;
  int fin;
  int niv;
};

bool canReachTop(vector<Ascensor> &ascensores, int maxH, int niv) {
  int curr = 0;

  for (int i = 0; i < ascensores.size(); i++) {
    if (ascensores[i].ini <= curr && ascensores[i].niv <= niv) {
      curr = max(curr, ascensores[i].fin);
    }
  }
  return curr == maxH;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<Ascensor> ascensores(n);
    int maxH = 0;
    for (int i = 0; i < n; i++) {
      cin >> ascensores[i].ini >> ascensores[i].fin >> ascensores[i].niv;
      maxH = max(maxH, ascensores[i].fin);
    }

    sort(ascensores.begin(), ascensores.end(), [](const Ascensor &a, const Ascensor &b) {
      if (a.ini == b.ini) return a.fin > b.fin;
      return a.ini < b.ini;
    });

    int low = 1, high = 1000000;
    int ans = high;

    while (high >= low) {
      int mid = (high - low) / 2 + low;

      if (canReachTop(ascensores, maxH, mid)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
