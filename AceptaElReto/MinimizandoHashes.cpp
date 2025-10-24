#include <bits/stdc++.h>
using namespace std;

struct TNode {
  TNode* nextA;
  TNode* nextB;
  int freq;

  TNode(TNode* nextA, TNode* nextB, int freq) {
    this->nextA = nextA;
    this->nextB = nextB;
    this->freq = freq;
  }
};

void dfs(TNode* curr, int &sum, int depth) {
  if (curr->freq == 1) {
    sum += depth;
    return;
  }

  if (curr->nextA != nullptr) dfs(curr->nextA, sum, depth + 1);
  if (curr->nextB != nullptr) dfs(curr->nextB, sum, depth + 1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    TNode* root = new TNode(nullptr, nullptr, n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      TNode* curr = root;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
          if (curr->nextA == nullptr) {
            curr->nextA = new TNode(nullptr, nullptr, 1);
            curr = curr->nextA;
          } else {
            curr = curr->nextA;
            curr->freq++;
          }
        } else {
          if (curr->nextB == nullptr) {
            curr->nextB = new TNode(nullptr, nullptr, 1);
            curr = curr->nextB;
          } else {
            curr = curr->nextB;
            curr->freq++;
          }
        }
      }
    }

    int sum = 0;

    dfs(root, sum, 0);

    cout << sum << "\n";
  }
  return 0;
}
