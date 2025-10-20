#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string line;
  while (getline(cin, line)) {
    vector<char> freq(26);

    for (int i = 0; i < line.size(); i++) {
      freq[line[i] - 'a']++;
    }

    int nOdds = 0, odd;
    for (int i = 0; i < freq.size(); i++) {
      if (freq[i] % 2) nOdds++, odd = i;
    }

    if (nOdds > 1) {
      cout << "NO HAY\n";
      continue;
    }

    stack<char> st;

    for (int i = 0; i < freq.size(); i++) {
      while (freq[i] >= 2) {
        char c = (i + 'a');
        cout << c;
        freq[i] -= 2;
        st.push(c);
      }
    }

    if (nOdds) {
      cout << (char) (odd + 'a');
    }

    while (!st.empty()) {
      cout << st.top();
      st.pop();
    }

    cout << "\n";

  }
  return 0;
}
