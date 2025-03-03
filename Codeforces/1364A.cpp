#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  bool todosDivisores = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % x) {
      todosDivisores = false;
    }
  }

  if (todosDivisores) {
    cout << -1 << endl;
    return;
  }

  vector<ll> prefixSum(n);
  prefixSum[0] = a[0];
  for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + a[i];

  ll alto = n - 1;
  ll bajo = 0;

  ll bestAns = -1;

  while (alto >= bajo) {
    ll sum = prefixSum[alto] - (bajo == 0 ? 0 : prefixSum[bajo - 1]);
    if (sum % x) {
      bestAns = max(bestAns, alto - bajo + 1);
      break;
    }

    ll sum2 = prefixSum[alto] - (bajo < 0 ? 0 : prefixSum[bajo]);
    ll sum3 = prefixSum[alto - 1] - (bajo == 0 ? 0 : prefixSum[bajo - 1]);

    if (sum2 % x) {
      bajo++;
    } else if (sum3 % x) {
      alto--;
    } else {
      alto--;
    }
  }

  alto = n - 1;
  bajo = 0;
  while (alto >= bajo) {
    ll sum = prefixSum[alto] - (bajo == 0 ? 0 : prefixSum[bajo - 1]);
    if (sum % x) {
      bestAns = max(bestAns, alto - bajo + 1);
      break;
    }

    ll sum2 = prefixSum[alto] - (bajo < 0 ? 0 : prefixSum[bajo]);
    ll sum3 = prefixSum[alto - 1] - (bajo == 0 ? 0 : prefixSum[bajo - 1]);

    if (sum2 % x) {
      bajo++;
    } else if (sum3 % x) {
      alto--;
    } else {
      bajo++;
    }
  }

  cout << bestAns << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
