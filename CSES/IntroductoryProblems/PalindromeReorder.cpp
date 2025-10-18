#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_map<char, int> freq;

  for (int i = 0; i < s.size(); i++) {
    freq[s[i]]++;
  }

  int countOdds = 0;
  for (const pair<char, int> &p : freq) {
    if (p.second % 2) countOdds++;
  }

  if (countOdds > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  string aux(s.size(), ' ');

  for (int i = 0; i < s.size() / 2 + (s.size() % 2); i++) {
    for (const pair<char, int> &p : freq) {
      if (i == s.size() / 2) {
        if (p.second == 1) {
          freq[p.first]--;
          aux[i] = p.first;
          break;
        }
      } else {
        if (p.second >= 2) {
          freq[p.first] -= 2;
          aux[i] = p.first;
          aux[s.size() - i - 1] = p.first;
          break;
        }
      }
    }
  }

  cout << aux << endl;
  return 0;
}
