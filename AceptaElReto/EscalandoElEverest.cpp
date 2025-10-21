#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> groups;
    vector<int> currGroup;
    for (int i = 0; i < n; i++) {
      if (currGroup.empty()) {
        currGroup.push_back(i);
        continue;
      }
      if (a[i] >= a[i - 1]) {
        a[i] = a[i - 1];
        currGroup.push_back(i);
      } else {
        groups.push_back(currGroup);

        currGroup = {i};
      }
    }

    if (!currGroup.empty()) {
      groups.push_back(currGroup);
    }

    int minG = INT_MAX, maxG = INT_MIN;
    for (int i = 0; i < groups.size(); i++) {
      minG = min(minG, (int) groups[i].size());
      maxG = max(maxG, (int) groups[i].size());
    }

    cout << groups.size() << " " << minG << " " << maxG << "\n";
  }

  return 0;
}
