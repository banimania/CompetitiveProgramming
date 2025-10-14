#include <bits/stdc++.h>
using namespace std;

map<char, vector<pair<char, char>>> mult = {
  {'a', {{'a', 'c'}, {'b', 'c'}, {'c', 'a'}}},
  {'b', {{'a', 'a'}, {'a', 'b'}, {'b', 'b'}}},
  {'c', {{'b', 'a'}, {'c', 'b'}, {'c', 'c'}}}
};

bool solve(int i, int j, const string &s, char letra, vector<vector<vector<int>>> &dp) {
  int l = letra - 'a';
  if (i == j) return dp[i][j][l] = s[i] == letra;
  if (dp[i][j][l] != -1) return dp[i][j][l];

  dp[i][j][l] = 0;
  for (int k = i; k < j && !dp[i][j][l]; k++) {
    for (const pair<char, char> &req : mult[letra]) {
      dp[i][j][l] |= (solve(i, k, s, req.first, dp) && solve(k + 1, j, s, req.second, dp));
    }
  }

  return dp[i][j][l];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  string s;
  while (cin >> s) {
    vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(s.size(), vector<int>(3, -1)));

    cout << (solve(0, s.size() - 1, s, 'a', dp) ? "SI" : "NO") << endl;
  }
  return 0;
}
