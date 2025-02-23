#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> servers(n, 0);

  for (int i = 0; i < q; i++) {
    int t, k, d;
    cin >> t >> k >> d;

    int serversAvailable = 0;
    vector<int> availableIndexes;

    for (int j = 0; j < servers.size() && availableIndexes.size() < k; j++) {
      if (servers[j] <= t) {
        serversAvailable++;
        availableIndexes.push_back(j);
      }
    }

    if (serversAvailable >= k) {
      int sumIds = 0;

      for (int j = 0; j < availableIndexes.size(); j++) {
        sumIds += (availableIndexes[j] + 1);
        servers[availableIndexes[j]] = t + d;
      }

      cout << sumIds << endl;
    } else {
      cout << -1 << endl;
      continue;
    }

  }

  return 0;
}
