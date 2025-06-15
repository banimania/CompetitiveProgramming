#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 0

void solve() {
  int n;
  while (cin >> n && n) {
    vector<int> target(n);
    for (int i = 0; i < n; i++) {
      cin >> target[i];
    }
    stack<int> entrada, est, salida;

    for (int i = n; i >= 1; i--) {
      entrada.push(i);
    }

    bool ans = true;
    int cnt = 0;

    while (!entrada.empty()) {
      if (target[cnt] == entrada.top()) {
        salida.push(entrada.top());
        entrada.pop();
        cnt++;
      } else if (!est.empty() && target[cnt] == est.top()) {
        salida.push(est.top());
        est.pop();
        cnt++;
      } else {
        est.push(entrada.top());
        entrada.pop();
      }
    }

    while (!est.empty()) {
      salida.push(est.top());
      est.pop();
    }

    cnt = n - 1;
    while (!salida.empty()) {
      if (salida.top() != target[cnt]) {
        ans = false;
        break;
      }

      salida.pop();
      cnt--;
    }

    cout << (ans ? "SI" : "NO") << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
