#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;

int n;
vector<tuple<int, int, int>> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
pair<int, int> rootPath[MAXN];

void dfs(int v, int p, int a, int b) {
  up[v][0] = p;
  for (int i = 1; i < LOG; i++) up[v][i] = up[up[v][i - 1]][i - 1];

  rootPath[v] = {a, b};

  for (auto [to, a_i, b_i] : adj[v]) {
    if (to == p) continue;
    depth[to] = depth[v] + 1;
    dfs(to, v, a + a_i, b + b_i);
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);

  int k = depth[a] - depth[b];
  for (int i = LOG - 1; i >= 0; i--) {
    if (k & (1 << i)) {
      a = up[a][i];
    }
  }

  if (a == b) return a;

  for (int i = LOG - 1; i >= 0; i--) {
    if (up[a][i] != up[b][i]) {
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--, v--;
    adj[u].push_back({v, a, b});
    adj[v].push_back({u, a, b});
  }

  depth[0] = 0;
  dfs(0, 0, 0, 0);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;

    int k = lca(u, v);
    int sumA = rootPath[u].first + rootPath[v].first - 2 * rootPath[k].first;
    int sumB = rootPath[u].second + rootPath[v].second - 2 * rootPath[k].second;
    int ans = 0;
    if (w > sumA) ans = (w - sumA + sumB - 1) / sumB;
    cout << ans << (i == q - 1 ? "" : " ");
  }
  cout << "\n";

  return 0;
}
