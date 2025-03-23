#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int pos = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == k) {
      pos = i + 1;
      break;
    }
  }

  if (pos == 1) cout << "fyrst" << endl;
  else if (pos == 2) cout << "naestfyrst" << endl;
  else cout << pos << " " << "fyrst" << endl;
  return 0;
}
