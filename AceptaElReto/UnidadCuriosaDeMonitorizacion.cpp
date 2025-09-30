#include <bits/stdc++.h>
using namespace std;

struct State {
  int id;
  int p;
  int inc;
};

int main() {
  int n;
  while (cin >> n && n) {
    priority_queue<State, vector<State>, function<bool(const State&, const State&)>> pq([](const State &a, const State &b) {
      if (a.p == b.p) return a.id > b.id;
      return a.p > b.p;
    });

    for (int i = 0; i < n; i++) {
      int id, p;
      cin >> id >> p;

      pq.push({id, p, p});
    }
    int k;
    cin >> k;

    while (k--) {
      cout << pq.top().id << endl;
      State next = {pq.top().id, pq.top().p + pq.top().inc, pq.top().inc};
      pq.pop();
      pq.push(next);
    }
    cout << "----" << endl;
  }
  return 0;
}
