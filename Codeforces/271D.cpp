#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 0

struct TNode {
  map<char, TNode*> next;
  bool word = false;
};

struct Trie {
  TNode* root;

  Trie() {
    root = new TNode();
  }

  bool insert(const string &s) {
    TNode* node = root;
    bool isNew = false;
    for (char c : s) {
      if (!node->next.count(c)) {
        isNew = true;
        node->next[c] = new TNode();
      }
      node = node->next[c];
    }

    if (!node->word) {
      node->word = true;
      return true;
    }

    return false;
  }
};

void solve() {
  string s;
  cin >> s;

  vector<bool> good(26);
  for (int i = 0; i < 26; i++) {
    char x;
    cin >> x;
    good[i] = x - '0';
  }

  vector<int> badSum(s.size());
  for (int i = 0; i < s.size(); i++) {
    badSum[i] = (i > 0 ? badSum[i - 1] : 0) + !good[s[i] - 'a'];
  }

  int k;
  cin >> k;

  int cnt = 0;
  Trie trie;

  set<string> str;
  for (int i = 0; i < s.size(); i++) {
    TNode* node = trie.root;
    for (int j = i; j < s.size(); j++) {
      if (badSum[j] - (i > 0 ? badSum[i - 1] : 0) <= k) {
        if (!node->next.count(s[j])) node->next[s[j]] = new TNode();
        node = node->next[s[j]];
        if (!node->word) {
          node->word = true;
          cnt++;
        }
      }
    }
  }

  cout << cnt << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
