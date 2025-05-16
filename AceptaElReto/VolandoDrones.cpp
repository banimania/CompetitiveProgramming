#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, a, b;
  while (cin >> n >> a >> b) {
    priority_queue<int> pilasA, pilasB;

    for (int i = 0; i < a; i++) {
      int x;
      cin >> x;

      pilasA.push(x);
    }

    for (int i = 0; i < b; i++) {
      int x;
      cin >> x;

      pilasB.push(x);
    }

    vector<ll> ans;

    priority_queue<int> pilasA2, pilasB2;
    while (!pilasA.empty() && !pilasB.empty()) {
      ll curr = 0;

      for (int i = 0; i < n && !pilasA.empty() && !pilasB.empty(); i++) {
        int pA = pilasA.top();
        pilasA.pop();
        int pB = pilasB.top();
        pilasB.pop();

        curr += min(pA, pB);
        
        if (pA > pB) {
          pilasA2.push(pA - pB);
        } else if (pB > pA) {
          pilasB2.push(pB - pA);
        }

      }

      if (curr > 0) ans.push_back(curr);

      while (!pilasA2.empty()) {
        pilasA.push(pilasA2.top());
        pilasA2.pop();
      }
      while (!pilasB2.empty()) {
        pilasB.push(pilasB2.top());
        pilasB2.pop();
      }
    }

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;
  }
  return 0;
}
