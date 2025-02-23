#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<bool> primes(3000005, true);

  int cnt = 0;
  for (int i = 2; i <= primes.size(); i++) {
    if (primes[i]) {
      cnt++;
      cout << i << " ";
      if (cnt == n) break;
      for (int j = i * i; j < primes.size(); j += i) {
        primes[j] = false;
      }
    }
  }
  cout << endl;

  return 0;
}
