#include <bits/stdc++.h>
using namespace std;

bool solve(int index, vector<vector<int>> &adj, map<int, int> &type) {
  if (index == adj.size()) {
    for (int i = 0; i < adj.size(); i++) {
      cout << i + 1 << " " << type[i] << endl;
    }
    return true;
  }

  for (int i = 1; i <= 4; i++) {
    bool possible = true;

    for (int neighbour : adj[index]) {
      if (type.count(neighbour) && type[neighbour] == i) {
        possible = false;
        break;
      }
    }

    if (possible) {
      type[index] = i;
      if (solve(index + 1, adj, type)) return true;
      type.erase(index);
    }
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);

  string s;
  map<int, int> type;
  while (cin >> s) {
    int index = s.find("-");

    string fn = s.substr(0, index);
    string sn = s.substr(index + 1);
    
    int u = stoi(fn) - 1;
    int v = stoi(sn) - 1;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve(0, adj, type);
  return 0;
}
