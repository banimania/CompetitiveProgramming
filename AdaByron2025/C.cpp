#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct State {
  int modulo;
  ll cost;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<int> nuggets(n);
    int gcd = 0;
    for (int i = 0; i < n; i++) {
      cin >> nuggets[i];
      gcd = __gcd(gcd, nuggets[i]);
    }

    if (gcd != 1) {
      cout << "IMPOSIBLE\n";
      continue;
    }

    priority_queue<State, vector<State>, function<bool(const State&, const State&)>> pq([](const State &a, const State &b) {
      return a.cost > b.cost;
    });
    vector<ll> best(nuggets[0], LLONG_MAX);
    best[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      if (best[curr.modulo] < curr.cost) continue;

      for (int i = 1; i < n; i++) {
        int next = (curr.modulo + nuggets[i]) % nuggets[0];
        int cost = curr.cost + nuggets[i];

        if (best[next] > cost) {
          best[next] = cost;
          pq.push({next, cost});
        }
      }
    }

    ll ans = 0;
    for (int i = 0; i < nuggets[0]; i++) {
      ans = max(ans, best[i]);
    }

    ans -= nuggets[0];

    cout << ans << "\n";
  }
  return 0;
}
