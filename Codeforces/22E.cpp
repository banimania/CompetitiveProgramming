#include <bits/stdc++.h>
using namespace std;

void dfs1(int current, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
  for (int neighbour : adj[current]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      dfs1(neighbour, adj, visited, st);
    }
  }

  st.push(current);
}

void dfs2(int current, vector<vector<int>> &adj, vector<int> &sccId, int id) {
  for (int neighbour : adj[current]) {
    if (sccId[neighbour] == -1) {
      sccId[neighbour] = id;
      dfs2(neighbour, adj, sccId, id);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n), adjT(n);
  for (int i = 0; i < n; i++) {
    int f;
    cin >> f;
    f--;
    adj[i].push_back(f);
    adjT[f].push_back(i);
  }

  vector<bool> visited(n, false);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs1(i, adj, visited, st);
    }
  }

  vector<int> sccId(n, -1);
  int id = 0;
  while (!st.empty()) {
    int current = st.top();
    st.pop();

    if (sccId[current] == -1) {
      sccId[current] = id;
      dfs2(current, adjT, sccId, id);
      id++;
    }
  }

  if (id == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> inDeg(id), outDeg(id);
  for (int i = 0; i < n; i++) {
    for (int neighbour : adj[i]) {
      if (sccId[i] != sccId[neighbour]) {
        inDeg[sccId[neighbour]]++;
        outDeg[sccId[i]]++;
      }
    }
  }

  vector<int> inDegZero, outDegZero;
  set<int> seen;
  for (int scc : sccId) {
    if (seen.count(scc)) continue;

    if (!inDeg[scc]) inDegZero.push_back(scc);
    if (!outDeg[scc]) outDegZero.push_back(scc);

    seen.insert(scc);
  }
 
  vector<int> rep(id, -1);
  for (int i = 0; i < n; i++) {
    if (rep[sccId[i]] == -1) {
      rep[sccId[i]] = i;
    }
  }
 
  // TODO: I love this problem :)
  bool endedIn = false, endedOut = false;
  int minEdges = max(inDegZero.size(), outDegZero.size());
  cout << minEdges << endl;
  for (int i = 0; i < minEdges; i++) {
    int in = 0, out = 0;

    if (!inDegZero.empty()) in = inDegZero[i % inDegZero.size()];
    if (!outDegZero.empty()) out = outDegZero[i % outDegZero.size()];
    
    if (in == out) {
      if (endedIn || inDegZero.empty()) ++in %= id;
      else if (endedOut || outDegZero.empty()) ++out %= id;
      else swap(out, outDegZero[(i + 1) % outDegZero.size()]);
    }

    if (in == id - 1) endedIn = true;
    if (out == id - 1) endedOut = true;

    cout << rep[out] + 1 << " " << rep[in] + 1 << endl;
  }

  return 0;
}
