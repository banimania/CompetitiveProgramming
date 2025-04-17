#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];

  sort(nums.begin(), nums.end());
  map<ll, ll> amount;
  for (int i = 0; i < nums.size(); i++) amount[nums[i]]++;

  vector<ll> newNums = {nums[0]};
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] != newNums[newNums.size() - 1]) newNums.push_back(nums[i]);
  }

  vector<ll> dp(newNums.size(), INT_MIN);

  for (int i = 0; i < newNums.size(); i++) {

    ll take = 0;
    if (i - 1 >= 0 && newNums[i] - 1 != newNums[i - 1]) {
      take = dp[i - 1];
    } else if (i - 2 >= 0) {
      take = dp[i - 2];
    }

    dp[i] = max(
      amount[newNums[i]] * newNums[i] + take,
      (i - 1 >= 0 ? dp[i - 1] : 0)
    );
  }

  cout << dp[dp.size() - 1] << endl;
  return 0;
}
