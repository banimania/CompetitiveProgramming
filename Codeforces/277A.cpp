#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<set<ll>> idiomas(n);
  vector<bool> visited(n, false);
  bool anyLang = false;

  for (ll i = 0; i < n; i++) {
    ll k;
    cin >> k;
    while (k--) {
      ll idioma;
      cin >> idioma;
      idiomas[i].insert(idioma);
      anyLang = true;
    }
  }

  if (!anyLang) {
    cout << n << endl;
    return;
  }

  map<ll, vector<ll>> langEmp;
  for (ll i = 0; i < n; i++) {
    for (ll idioma : idiomas[i]) {
      langEmp[idioma].push_back(i);
    }
  }

  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (!visited[i]) {
      cnt++;
      queue<ll> q;
      q.push(i);
      visited[i] = true;

      while (!q.empty()) {
        ll employee = q.front();
        q.pop();

        for (ll idioma : idiomas[employee]) {
          for (ll neighbor : langEmp[idioma]) {
            if (!visited[neighbor]) {
              visited[neighbor] = true;
              q.push(neighbor);
            }
          }
        }
      }
    }
  }

  cout << cnt - 1 << endl;
}

int main() {
  solve();
  return 0;
}
 
