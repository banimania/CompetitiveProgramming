#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> term(10);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      char final = s.back();
      int num = final - '0';

      term[num]++;
    }

    int best = 0, maxOc = 1;
    for (int i = 1; i < 10; i++) {
      if (term[i] > term[best]) {
        best = i;
        maxOc = 1;
      } else if (term[i] == term[best]) {
        maxOc++;
      }
    }

    if (maxOc == 1) {
      cout << best << "\n";
    } else {
      cout << "VARIAS\n";
    }
  }
  return 0;
}

