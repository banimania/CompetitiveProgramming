// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main() {
//   int n, s, t, p;
//   while (cin >> n >> s >> t >> p) {
//     s--;
//     vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//     for (int i = 0; i < n; i++) {
//       dp[i][i] = 0;
//     }

//     for (int i = 0; i < p; i++) {
//       int a, b, t;
//       cin >> a >> b >> t;
//       a--, b--;
//       dp[a][b] = t;
//     }

//     for (int k = 0; k < n; k++) {
//       for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//           if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][j] > dp[i][k] + dp[k][j]) {
//             dp[i][j] = dp[i][k] + dp[k][j];
//           }
//         }
//       }
//     }

//     int nRatones = 0;

//     for (int i = 0; i < n; i++) {
//       if (i == s) continue;
//       if (dp[i][s] <= t) nRatones++;
//     }

//     cout << nRatones << endl;

//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, dist;
};

int main() {
  int n, s, t, p;
  while (cin >> n >> s >> t >> p) {
    s--;

    map<int, vector<pair<int, int>>> adj;
    map<int, int> bestDist;
    for (int i = 0; i < p; i++) {
      int a, b, t;
      cin >> a >> b >> t;
      a--, b--;
      
      adj[b].push_back({a, t});
      bestDist[i] = INT_MAX;
    }
    bestDist[s] = 0;

    priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
      return a.dist > b.dist;
    });

    pq.push({s, 0});

    while (!pq.empty()) {
      State current = pq.top();
      pq.pop();

      for (pair<int, int> edge : adj[current.pos]) {
        int neighbour = edge.first;
        int cost = edge.second;

        int newDist = current.dist + cost;
        if (bestDist[neighbour] > newDist) {
          bestDist[neighbour] = newDist;
          pq.push({neighbour, newDist});
        }
      }
    }

    int nRatones = 0;

    for (pair<int, int> dist : bestDist) {
      if (dist.first == s) continue;
      if (dist.second <= t) nRatones++;
    }

    cout << nRatones << endl;
  }
}
