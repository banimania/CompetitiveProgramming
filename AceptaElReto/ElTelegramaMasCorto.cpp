#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<char, string> morse = {
  {'A', ".-"},
  {'B', "-..."},
  {'C', "-.-."},
  {'D', "-.."},
  {'E', "."},
  {'F', "..-."},
  {'G', "--."},

  {'H', "...."},
  {'I', ".."},
  {'J', ".---"},
  {'K', "-.-"},
  {'L', ".-.."},
  {'M', "--"},
  {'!', "-.-.--"},


  {'N', "-."},
  {'O', "---"},
  {'P', ".--."},
  {'Q', "--.-"},
  {'R', ".-."},
  {'S', "..."},
  {'T', "-"},

  {'U', "..-"},
  {'V', "...-"},
  {'W', ".--"},
  {'X', "-..-"},
  {'Y', "-.--"},
  {'Z', "--.."},
  {'?', "..--.."}
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string s;
    getline(cin, s);
    ll tot = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        tot += 5;
        continue;
      }
      string c = morse[s[i]];

      int puntos = 0;
      int rayas = 0;
      for (int j = 0; j < c.size(); j++) {
        if (c[j] == '.') puntos++;
        else rayas++;
      }
      puntos += c.size() - 1;
      puntos += rayas * 3;
      // cout << c<< " => " << puntos << endl;

      if (i < s.size() - 1 && s[i + 1] != ' ') puntos += 3;

      tot += puntos;

    }

    cout << tot << "\n";
  }
  return 0;
}
