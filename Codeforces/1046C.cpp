#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  d--;

  vector<int> ranks(n);
  vector<int> pts(n);
  for (int i = 0; i < n; i++) cin >> ranks[i];
  for (int i = 0; i < n; i++) cin >> pts[i];

  ranks[d] += pts[0];
  int ans = d + 1;
  for (int i = 0; i < d; i++) {
    if (ranks[d] >= ranks[i] + pts[pts.size() - 1]) {
      ans--;
      pts.pop_back();
    }
  }
	cout << ans << endl;
  return 0;
}
