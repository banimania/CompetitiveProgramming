#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, l;
  while (cin >> n >> l) {
    vector<pair<int, int>> cuerdas(n);
    for (int i = 0; i < n; i++) {
      cin >> cuerdas[i].first >> cuerdas[i].second;
    }

    vector<ll> dpM(l + 1);
    dpM[0] = 1;
    vector<ll> dpI(l + 1, LLONG_MAX);
    dpI[0] = 0;
    vector<ll> dpE(l + 1, LLONG_MAX);
    dpE[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = l; j >= cuerdas[i].first; j--) {
        if (dpI[j - cuerdas[i].first] != LLONG_MAX) {
          dpM[j] += dpM[j - cuerdas[i].first];
          dpI[j] = min(dpI[j], dpI[j - cuerdas[i].first] + 1);
          dpE[j] = min(dpE[j], dpE[j - cuerdas[i].first] + cuerdas[i].second);
        }
      }
    }

    if (dpE[l] == LLONG_MAX) {
      cout << "NO\n";
    } else {
      cout << "SI " << dpM[l] << " " << dpI[l] << " " << dpE[l] << "\n";
    }
  }
  return 0;
}
