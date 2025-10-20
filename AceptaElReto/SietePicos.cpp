#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[(i + 1) % n] && nums[i] > nums[(i - 1 + n) % n]) ans++;
    }

    cout << ans << "\n";
  }
  return 0;
}
