#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    map<char, int> freq1, freq2;

    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] == ' ') continue;
      freq1[tolower(s1[i])]++;
    }
    for (int i = 0; i < s2.size(); i++) {
      if (s2[i] == ' ') continue;
      freq2[tolower(s2[i])]++;
    }

    bool anagrama = true;
    for (pair<char, int> par : freq1) {
      freq2[par.first] -= par.second;
    }

    for (pair<char, int> par : freq2) {
      if (par.second) {
        anagrama = false;
        break;
      }
    }

    cout << (anagrama ? "SI" : "NO") << endl;
  }
  return 0;
}
