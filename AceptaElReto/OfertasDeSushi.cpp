#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll n, p;
  while (cin >> n >> p) {
    vector<int> price(n);
    for (int i = 0; i < n; i++) {
      cin >> price[i];
    }

    vector<int> needed(n);
    for (int i = 0; i < n; i++) {
      cin >> needed[i];
    }

    ll fixed = 0;
    for (int i = 3; i < n; i++) {
      fixed += needed[i] * price[i];
    }

    vector<pair<int, int>> x = {{needed[0], price[0]}, {needed[1], price[1]}, {needed[2], price[2]}};
    sort(x.begin(), x.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
      if (a.first == b.first) return a.second < b.second;
      return a.first < b.first;
    });

    ll currLotes = min({x[0].first, x[1].first, x[2].first});

    // sin completar nada
    ll precioLotes = currLotes * p + (x[1].first - currLotes) * x[1].second + (x[2].first - currLotes) * x[2].second;

    // completar hasta el segundo más alto?
    currLotes = x[1].first;
    precioLotes = min(precioLotes, currLotes * p + (x[2].first - currLotes) * x[2].second);

    // completar todos?
    currLotes = x[2].first;
    precioLotes = min(precioLotes, currLotes * p);

    ll ans = precioLotes + fixed;
    cout << ans << "\n";
  }

  return 0;
}
