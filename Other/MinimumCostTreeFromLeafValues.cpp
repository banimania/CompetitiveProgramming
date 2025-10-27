class Solution {
public:
  int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &dpL, vector<int> &arr) {
    if (dp[i][j] != -1) return dp[i][j];

    if (i == j) return dp[i][j] = 0;
    if (i + 1 == j) {
      return dp[i][j] = arr[i] * arr[j];
    }
    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
      dp[i][j] = min(dp[i][j], largestLeaf(i, k, dpL, arr) * largestLeaf(k + 1, j, dpL, arr) + solve(i, k, dp, dpL, arr) + solve(k + 1, j, dp, dpL, arr));
    }

    return dp[i][j];
  }

  int largestLeaf(int i, int j, vector<vector<int>> &dpL, vector<int> &arr) {
    if (dpL[i][j] != -1) return dpL[i][j];
    if (i == j) return dpL[i][j] = arr[i];

    for (int k = i; k < j; k++) {
      dpL[i][j] = max({dpL[i][j], largestLeaf(i, k, dpL, arr), largestLeaf(k + 1, j, dpL, arr)});
    }

    return dpL[i][j];
  }

  int mctFromLeafValues(vector<int>& arr) {
    vector<vector<int>> dpL(arr.size(), vector<int>(arr.size(), -1));
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    return solve(0, arr.size() - 1, dp, dpL, arr);
  }
};
