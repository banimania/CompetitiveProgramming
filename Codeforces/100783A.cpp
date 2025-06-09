#include <bits/stdc++.h>
using namespace std;

int solve(int index, int sum, int result, map<char, int> &letter, vector<char> &order, vector<string> &words, int nzero, vector<bool> &used, map<char, vector<pair<int, int>>> &xd) {
  int ans = 0;

  if (index == order.size()) {
    return sum == result;
  }

  for (int i = (index < nzero ? 1 : 0); i < 10; i++) {
    if (!used[i]) {
      used[i] = true;

      int resultAdd = 0, sumAdd = 0;
      for (auto [indexWord, indexChar] : xd[order[index]]) {
        if (indexWord == words.size() - 1) {
          resultAdd += i * pow(10, (words[indexWord].size() - 1) - indexChar);
        } else {
          sumAdd += i * pow(10, (words[indexWord].size() - 1) - indexChar);
        }
      }

      letter[order[index]] = i;
      ans += solve(index + 1, sum + sumAdd, result + resultAdd, letter, order, words, nzero, used, xd);

      used[i] = false;
    }
  }

  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<string> words(n);
  set<char> seen;
  vector<char> order;
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  for (int i = 0; i < n; i++) {
    if (!seen.count(words[i][0])) {
      order.push_back(words[i][0]);
      seen.insert(words[i][0]);
    }
  }

  int nzero = seen.size();
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < words[i].size(); j++) {
      if (!seen.count(words[i][j])) {
        order.push_back(words[i][j]);
        seen.insert(words[i][j]);
      }
    }
  }

  map<char, vector<pair<int, int>>> xd;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < words[i].size(); j++) {
      xd[words[i][j]].push_back({i, j});
    }
  }

  map<char, int> letter;
  vector<bool> used(10, false);
  cout << solve(0, 0, 0, letter, order, words, nzero, used, xd) << endl;
  return 0;
}
