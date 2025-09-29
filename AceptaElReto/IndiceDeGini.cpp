#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
  ll n, k;
  ll cSum = 0;
  while (cin >> n >> k) {
    if (!n && !k) break;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll x;
    for (int i = 0; i < n; i++) {
      cin >> x;

      if (pq.size() < k) {
        pq.push(x);
      } else if (x > pq.top()) {
        pq.pop();
        pq.push(x);
      }

      cSum += x;
    }

    ll masRico = 0;

    while (!pq.empty()) {
      masRico += pq.top();
      pq.pop();
    }

    cout << cSum << " " << masRico << endl;
    cSum = 0;
  }
  return 0;
}
