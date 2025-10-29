#include <bits/stdc++.h>
using namespace std;

struct TNode {
  int end = 0;
  int count = 0;
  TNode* child[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
};

void addWord(TNode* curr, const vector<int> &s) {
  curr->count++;
  for (int x : s) {
    if (!curr->child[x]) curr->child[x] = new TNode();
    curr = curr->child[x];
    curr->count++;
  }
  curr->end++;
}

void freeTrie(TNode* node) {
  if (!node) return;
  for (int i = 0; i < 5; i++) freeTrie(node->child[i]);
  delete node;
}

int searchWord(TNode* curr, const vector<int> &suffix, const vector<vector<int>> &words, int str, int i) {
  if (!curr) return 0;

  if (i == words[str].size()) return curr->end;
  if (i == suffix[str]) return curr->count;

  int ans = 0;
  int x = words[str][i];

  if (x != 4) {
    if (curr->child[x] != nullptr) ans += searchWord(curr->child[x], suffix, words, str, i + 1);
    if (curr->child[4] != nullptr) ans += searchWord(curr->child[4], suffix, words, str, i + 1);
  } else {
    for (int j = 0; j < 5; j++) {
      if (curr->child[j] != nullptr) ans += searchWord(curr->child[j], suffix, words, str, i + 1);
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<vector<int>> words(n);
    TNode* root = new TNode();

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (char c : s) {
        int x;
        if (c == 'A') x = 0;
        else if (c == 'C') x = 1;
        else if (c == 'G') x = 2;
        else if (c == 'T') x = 3;
        else x = 4;

        words[i].push_back(x);
      }
    }

    int m = words[0].size();
    vector<int> order(m);
    for (int i = 0; i < order.size(); i++) order[i] = i;
    sort(order.begin(), order.end(), [&](int i, int j) {
      int ci = 0, cj = 0;
      for (int k = 0; k < n; k++){
        if (words[k][i] == 4) ci++;
        if (words[k][j] == 4) cj++;
      }
      return ci < cj;
    });

    vector<vector<int>> orderWords(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        orderWords[i][j] = words[i][order[j]];
      }
    }

    for (int i = 0; i < n; i++) addWord(root, orderWords[i]);

    vector<int> suffix(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = m - 1; j >= 0; j--) {
        if (orderWords[i][j] != 4) break;
        suffix[i] = j;
      }
    }

    for (int i = 0; i < n; i++) {
      cout << searchWord(root, suffix, orderWords, i, 0) - 1 << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    freeTrie(root);
  }

  return 0;
}
