#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> v(n);
    int minValue = v[0], minPos = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (minValue > v[i]) {
        minValue = v[i];
        minPos = i;
      }
    }

    vector<int> sorted(v.begin(), v.end());
    sort(sorted.begin(), sorted.end());

    int o = 0;
    int target = 0;
    for (int i = minPos; i < n; i++) {
      if (sorted[target] == v[i]) {
        target++;
        o++;
      }
    }

    cout << n - o << "\n";
  }
}
