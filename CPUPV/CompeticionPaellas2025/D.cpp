#include <bits/stdc++.h>
using namespace std;

int MAXN = 1e7 + 5;
vector<bool> prime(MAXN, true);
vector<int> prefPrime(MAXN);

typedef long long ll;

void sieve() {
  prime[0] = false, prime[1] = false;
  
  for (int i = 2; i * i < MAXN; i++) {
    if (prime[i]) {
      for (int j = i * i; j < MAXN; j += i) {
        prime[j] = false;
      }
    }
  }

  for (int i = 2; i < MAXN; i++) {
    prefPrime[i] = prefPrime[i - 1] + prime[i];
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];

  vector<int> sortedC(c.begin(), c.end());
  sort(sortedC.begin(), sortedC.end());

  int mid;
  if (n % 2) mid = sortedC[n / 2];
  else mid = (sortedC[n / 2] + sortedC[n / 2 - 1]) / 2;

  int primoLeg = -1;
  int curr = 0;

  while (primoLeg == -1) {
    int pos = max(0, mid + curr), neg = mid - curr;

    if (prime[pos] && !prime[neg]) {
      primoLeg = pos;
      break;
    } else if (prime[neg] && !prime[pos]) {
      primoLeg = neg;
      break;
    } else if (prime[pos] && prime[neg]) {
      ll distPos = 0, distNeg = 0;
      for (int i = 0; i < n; i++) {
        distPos += abs(pos - c[i]);
        distNeg += abs(neg - c[i]);
      }

      if (distPos >= distNeg) primoLeg = neg;
      else if (distPos < distNeg) primoLeg = pos;

      break;
    }
    curr++;
  }
  cout << primoLeg << endl;
  for (int i = 0; i < n; i++) {
    int dif = 0;

    if (primoLeg > c[i]) dif = prefPrime[primoLeg] - (c[i] > 0 ? prefPrime[c[i] - 1] : 0);
    else if (primoLeg < c[i]) dif = prefPrime[c[i]] - prefPrime[primoLeg - 1];

    cout << dif << " ";
  }
  cout << endl;
}

int main() {
  sieve();

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
