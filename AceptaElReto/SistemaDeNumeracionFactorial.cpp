#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    ordered_set s;
    for (int i = 0; i < n; i++) {
      s.insert(i + 1);
    }

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      int curr = *s.find_by_order(x);
      s.erase(curr);

      cout << curr << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
  }
  return 0;
}
