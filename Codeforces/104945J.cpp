#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p;
  cin >> n >> p;

  vector<int> indeg(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    indeg[u]++;
    indeg[v]++;
  }

  int minDeg = *min_element(indeg.begin(), indeg.end());
  int nh = 0;
  for (int i = 0; i < n; i++) {
    if (indeg[i] == minDeg) nh++;
  }

  int wpl = p / nh;
  int state = 0;
  if (p % nh == 0) state = 0;
  else if (p % nh == 1) state = 1;
  else state = 2;
  cout << 2 * wpl + state << endl;
  return 0;
}
