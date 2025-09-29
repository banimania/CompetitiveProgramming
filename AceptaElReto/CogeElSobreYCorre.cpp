#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k && n) {
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++) {
      cin >> nums[i];
    }

    deque<int> dq;
    for (int i = 0; i < k; i++) {
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }

      dq.push_back(i);
    }

    cout << nums[dq.front()];

    for (int i = k; i < n; i++) {
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }

      while (!dq.empty() && i - dq.front() >= k) {
        dq.pop_front();
      }

      dq.push_back(i);

      cout << " " << nums[dq.front()];
    }

    cout << endl;
  }

  return 0;
}
