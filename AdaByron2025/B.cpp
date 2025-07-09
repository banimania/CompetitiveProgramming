#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, vector<int> &primes) {
  ll currSum = primes[0];

  ll i = 0, j = 0;

  while (currSum != n) {
    if (currSum > n) {
      if (i >= j) {
        cout << "NO" << endl;
        return;
      }
      currSum -= primes[i];
      i++;
      continue;
    } else {
      j++;
      if (i >= primes.size() || j >= primes.size()) break;
      currSum += primes[j];
    }
  }

  if (currSum == n && j > i) {
    cout << primes[i] << " " << primes[j] << endl;
    return;
  }

  cout << "NO" << endl;
}

int main() {
  vector<bool> isPrime(1e7 + 5, true);
  isPrime[0] = false;
  isPrime[1] = false;
  vector<int> primes;
  for (int i = 2; i < 1e7 + 5; i++) {
    if (isPrime[i]) {
      primes.push_back(i);

      for (int j = 2 * i; j < 1e7 + 5; j += i) {
        isPrime[j] = false;
      }
    }
  }

  int n;
  while (cin >> n && n) {
    solve(n, primes);
  }

  return 0;
}
