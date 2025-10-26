#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  while (getline(cin, s)) {
    queue<int> nextFree;
    bool last = true;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '.') {
        nextFree.push(i);
      } else if (s[i] == '|') {
        last = false;
        while (!nextFree.empty()) nextFree.pop();
      } else {
        if (last) {
          s[i] = '.';
          continue;
        }
        if (!nextFree.empty()) {
          swap(s[i], s[nextFree.front()]);
          nextFree.pop();
          nextFree.push(i);
        }
      }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int q;
      cin >> q;
      q--;
      cout << s[q] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    cin.ignore();
  }


  return 0;
}
