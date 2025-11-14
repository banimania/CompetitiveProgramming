#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, k;
  while (cin >> n >> k) {
    if (!n && !k) break;
    queue<int> q;
    ll curr = 0;
    ll best = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      q.push(x);
      curr += x;

      while (curr >= k) {
        best = min(best, curr);
        curr -= q.front();
        q.pop();
      }
    }

    cout << (best == LLONG_MAX ? "IMPOSIBLE" : to_string(best)) << "\n";
    
  }
  return 0;
}
