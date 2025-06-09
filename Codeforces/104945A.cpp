#include <bits/stdc++.h>
using namespace std;

struct Card {
  char tier;
  int n;
};

int index(char tier, const string& order) {
  if (tier == 'C') return 4;
  for (int i = 0; i < 4; i++) {
    if (order[i] == tier) return i;
  }
  return -1;
}

int lis(vector<Card>& a, const string& order) {
  vector<pair<int, int>> tail;
  for (auto& x : a) {
    pair<int, int> val = {index(x.tier, order), x.n};
    auto it = lower_bound(tail.begin(), tail.end(), val);
    if (it == tail.end()) tail.push_back(val);
    else *it = val;
  }
  return tail.size();
}

int main() {
  int n;
  cin >> n;
  vector<Card> cards(n);

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int x = stoi(s.substr(1, s.size() - 1));

    cards[i] = {s[0], x};
  }

  int ans = INT_MAX;
  string order = "ERSW";
  do {
    ans = min(ans, n - lis(cards, order));
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << endl;

  return 0;
}
