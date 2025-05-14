#include <bits/stdc++.h>
using namespace std;

struct Node {
  double x, y, sat;
  string id, name;
};

double distNodes(Node &a, Node &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool dfs(int pos, double sat, double time, int target, double targetSat, double difTime, vector<vector<int>> &adj, vector<bool> &visited, vector<Node> &nodes, vector<pair<int, bool>> &prev) {
  if (time > difTime) return false;

  if (pos == target) {
    if (abs(sat - targetSat) < 0.1) {
      cout << "PATH FOUND: " << setprecision(3) << fixed << sat << " ";

      vector<pair<int, bool>> path = {{pos, false}};

      while (prev[pos].first != -1) {
        path.push_back({prev[pos].first, prev[pos].second});

        pos = prev[pos].first;
      }

      reverse(path.begin(), path.end());

      for (int i = 0; i < path.size(); i++) {
        cout << (path[i].second ? "" : "!") << nodes[path[i].first].id << (i == path.size() - 1 ? "" : " ");
      }
      cout << endl;

      // DEBUG
      /*
      double check = 0;
      for (int i = 0; i < path.size(); i++) {
        if (path[i].second) {
          check += nodes[path[i].first].sat;
          cout << "+ (" << nodes[path[i].first].sat << ") ";
        }
      }

      for (int i = 1; i < path.size(); i++) {
        double time = distNodes(nodes[path[i].first], nodes[path[i - 1].first]) / 0.06666666f;
        check -= time;
        cout << "- (" << time << ") ";
      }
      cout << endl;

      cout << "CHECK = " << check << endl;
      */
      // END DEBUG

      return true;
    }
    return false;
  }

  for (int neighbour : adj[pos]) {
    if (visited[neighbour]) continue;

    double costTime = distNodes(nodes[pos], nodes[neighbour]) / 0.06666666666f;

    visited[neighbour] = true;
    prev[neighbour] = {pos, 0};
    if (dfs(neighbour, sat - costTime, time + costTime, target, targetSat, difTime, adj, visited, nodes, prev)) return true;
    prev[neighbour] = {-1, 0};
    visited[neighbour] = false;
    
    visited[neighbour] = true;
    prev[neighbour] = {pos, 1};
    if (dfs(neighbour, sat - costTime + nodes[pos].sat, time + costTime + 15, target, targetSat, difTime, adj, visited, nodes, prev)) return true;
    prev[neighbour] = {-1, 0};
    visited[neighbour] = false;
  }
  visited[pos] = false;
  return false;
}

int main() {
  string tokenMapa;
  cin >> tokenMapa;
  int n, m;

  int cnt = 1;
  while (cin >> n >> m) {
    map<string, int> ident;
    vector<Node> nodes(n);
    string line;
    cin.ignore();
    for (int i = 0; i < n; i++) {
      getline(cin, line);
      istringstream iss(line);
      iss >> nodes[i].x >> nodes[i].y >> nodes[i].sat >> nodes[i].id;
      ident[nodes[i].id] = i;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      string nameU, nameV;
      cin >> nameU >> nameV;

      int u = ident[nameU], v = ident[nameV];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cout << "MAP " << cnt << endl;

    string tokenArrivals;
    cin >> tokenArrivals;

    string startTime;
    while (cin >> startTime) {
      if (startTime.length() != 5) break;

      string startId, endTime, endId;
      double targetSat;
      cin >> startId >> endTime >> endId >> targetSat;

      int startMin = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
      int endMin = stoi(endTime.substr(0, 2)) * 60 + stoi(endTime.substr(3, 2));

      int difTime;
      if (startMin < endMin) difTime = endMin - startMin;
      else difTime = 1440 - startMin + endMin;

      vector<bool> visited(n);
      vector<pair<int, bool>> prev(n, {-1, 0});
      visited[ident[startId]] = true;
      if (!dfs(ident[startId], 0, 0, ident[endId], targetSat, difTime, adj, visited, nodes, prev)) {
        visited[ident[startId]] = true;
        if (!dfs(ident[startId], nodes[ident[startId]].sat, 15, ident[endId], targetSat, difTime, adj, visited, nodes, prev)) {
          cout << "Impossible!" << endl;
        }
      }
    }

    cnt++;
  }
}
