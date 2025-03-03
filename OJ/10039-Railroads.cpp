#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, time;
};

void solve(int tt) {
  int c;
  cin >> c;

  map<string, int> nodes;
  for (int i = 0; i < c; i++) {
    string name;
    cin >> name;
    nodes[name] = i;
  }

  vector<vector<pair<int, int>>> adj(c, vector<pair<int, int>>(c));

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int ti;
    cin >> ti;

    int lastNode;

    for (int j = 0; j < ti; j++) {
      string timeStr, name;
      cin >> timeStr >> name;

      int node = nodes[name];
      int time = stoi(timeStr.substr(0, 2)) * 60 + stoi(timeStr.substr(3, 2));

      if (j != 0 && j != ti - 1) {
        adj[lastNode].push_back({node, time});
      }

      lastNode = node;
    }
  }

  string earliestTimeStr, origin, destination;
  cin >> earliestTimeStr >> origin >> destination;

  int earliestTime = stoi(earliestTimeStr.substr(0, 2)) * 60 + stoi(earliestTimeStr.substr(3, 2));
  int start = nodes[origin], end = nodes[destination];

  priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
    return a.time > b.time;
  });
  vector<int> bestTime(c, INT_MAX);

  pq.push({start, earliestTime});
  bestTime[start] = earliestTime;

  while (!pq.empty()) {

  }

  cout << "Scenario " << tt << endl;
  if (bestTime[end] == INT_MAX) {
    cout << "No connection" << endl;
  } else {
    cout << "Departure " << bestTime[start] << endl;
    cout << "Arrival " << bestTime[end] << endl;

  }
  cout << endl;

}

int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    solve(t);
  }
  return 0;
}
