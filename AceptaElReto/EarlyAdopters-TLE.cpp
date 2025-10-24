#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

typedef long long ll;

bool solve(int low, int high, int k, vector<int> &orden, int currHeight) {
  if (low > high) return true;
  if (currHeight > k) return false;

  int lowest = INT_MAX;
  for (int i = low; i <= high; i++) {
    int sz = orden.size();
    orden.push_back(i);

    if (solve(low, i - 1, k, orden, currHeight + 1) && solve(i + 1, high, k, orden, currHeight + 1)) {
      return true;
    }

    while (orden.size() != sz) orden.pop_back();
  }

  return false;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> orden;

  if (!solve(1, n, k, orden, 1)) {
    cout << "IMPOSIBLE" << endl;
    return;
  }

  for (int i = 0; i < orden.size(); i++) {
    cout << orden[i] << (i != orden.size() - 1 ? " " : "");
  }
  cout << endl;
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
