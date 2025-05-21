// https://cses.fi/problemset/task/1687
 
#include <bits/stdc++.h>
using namespace std;
 
void precalc(vector<int> &parent, vector<vector<int>> &up) {
  for (int i = 0; i < (int) parent.size(); i++) {
    up[i][0] = parent[i];
  }
 
  for (int j = 1; j < 32; j++) {
    for (int i = 0; i < (int) parent.size(); i++) {
      if (up[i][j - 1] != -1) {
        up[i][j] = up[up[i][j - 1]][j - 1];
      }
    }
  }
}
 
int query(int x, int k, vector<vector<int>> &up) {
  int curr = x;
 
  for (int i = 0; i < 32 && curr != -1; i++) {
    if ((1 << i) & k) {
      curr = up[curr][i];
    }
  }
 
  return (curr == -1 ? -1 : curr + 1);
}
 
int main() {
  int n, q;
  cin >> n >> q;
 
  vector<int> parent(n, -1);
 
  for (int i = 1; i < n; i++) {
    cin >> parent[i];
    parent[i]--;
  }
 
  vector<vector<int>> up(n, vector<int>(32, -1));
  precalc(parent, up);
  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
 
    cout << query(x - 1, k, up) << endl;
  }
  return 0;
}
