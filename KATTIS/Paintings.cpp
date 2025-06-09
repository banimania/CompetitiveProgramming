#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<bool> &freeColors, vector<set<int>> &adj, int &ways, vector<int> &current, vector<int> &favourite) {
  if (index == adj.size()) {
    if (favourite.empty()) {
      favourite = current;
    }
    ways++;
    return;
  }

  int last = -1;
  if (!current.empty()) last = current.back();
  for (int cId = 0; cId < freeColors.size(); cId++) {
    if (freeColors[cId]) {
      if (!adj[cId].count(last)) {
        freeColors[cId] = 0;
        current.push_back(cId);

        solve(index + 1, freeColors, adj, ways, current, favourite);

        current.pop_back();
        freeColors[cId] = 1;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;

  unordered_map<string, int> colors;
  vector<string> names(n);
  vector<set<int>> adj(n);
  vector<bool> freeColors(n, 1);
  for (int i = 0; i < n; i++) {
    string color;
    cin >> color;

    colors[color] = i;
    names[i] = color;
  }
  
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string c1, c2;
    cin >> c1 >> c2;

    int id1 = colors[c1], id2 = colors[c2];
    adj[id1].insert(id2);
    adj[id2].insert(id1);
  }

  int ways = 0;
  vector<int> favourite, current;

  solve(0, freeColors, adj, ways, current, favourite);
  cout << ways << endl;
  for (int i = 0; i < favourite.size(); i++) {
    cout << names[favourite[i]] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
