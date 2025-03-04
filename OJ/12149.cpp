#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  vector<ll> sqSum(101);
  ll sum = 0;
  for (int i = 1; i <= 100; i++) {
    sqSum[i] = sqSum[i - 1] + (i * i);
  }

  int n;
  while (cin >> n && n) {
    cout << sqSum[n] << endl;
  }
  return 0;
}
