#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(8200000, true);
vector<int> primes;
vector<int> g(500005);

void solve() {
  int i;
  cin >> i;

  cout << g[i] << endl;
}

int main() {
  prime[0] = false;
  prime[1] = false;

  for (int i = 2; i < 8200000; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j < 8200000; j += i) {
        prime[j] = false;
      }
    }
  }

  int cnt = 0;
  int curr = 0;
  while (cnt < g.size()) {
    if (prime[primes[curr] + 2]) {
      curr++;
    } else {
      g[cnt] = primes[curr] + 2;
      curr++;
      cnt++;
    }
  }

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
