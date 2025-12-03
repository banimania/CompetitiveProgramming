#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool repetido(const string &a) {
  bool repetido = true;

  int n = a.size();

  if (n % 2) return false;

  for (int i = 0; i < n / 2; i++) {
    if (a[i] != a[i + n / 2]) {
      repetido = false;
      break;
    }
  }

  return repetido;
}

pair<string,int> factorizar(const string &s) {
  int n = s.size();
  vector<int> pi(n);

  // pi[i] = long. del longest prefix de s que también es suffix del substring que termina en i
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }

  int periodo = n - pi[n - 1];

  if (n % periodo == 0) {
    return {s.substr(0, periodo), n / periodo};
  } else {
    return {s, 1}; // no es potencia de un patrón más pequeño
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll ans = 0;
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    string rango;
    while (getline(ss, rango, ',')) {
      int idx = rango.find("-");

      ll start = stoll(rango.substr(0, idx));
      ll end = stoll(rango.substr(idx + 1, rango.size() - idx - 1));

      cout << "from " << start << " to " << end << endl;
      for (ll i = start; i <= end; i++) {
        string k = to_string(i);

        int fact = factorizar(k).second;

        if (fact >= 2) {
          cout << "invalid id = " << k << endl;
          ans += i;
        }
      }
    }

  }

  cout << ans << "\n";

  return 0;
}
